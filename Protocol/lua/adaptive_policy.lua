-- adaptive_policy.lua 
-- A minimal adaptive policy, template for Adaptive OS,
-- Exposed APIs assumed: 
-- system.time(), system.log(tag, table).. 
-- sensor.get(name) -> table{distance, confidence}..
-- sync.put(key, value) -> persist policy parameters..
-- control.send(cmd).. 

local policy = {}
local sync = {}
local control = {}
local system = {}
local safety = {}

-- internal state (persistence via sync).. 
local params = 
{
    follow_distance = 20.0,  -- meters..
    attention_threshold = 0.20, 
    speed_limit = 25.0 -- m/s
}

-- need persisted overrides on load(sandbox should call).. 
if sync and sync.get then 
    local saved = sync.get("Adaptive_policy.params")
    if saved and type(saved) == "table" then 
        for k,v in pairs(saved) do params[k] = v end 
    end 
end 

function policy.on_tick(snapshot)
    -- snapshot contains sensor + runtime metrics.. 
    local lidar = snapshot.lidar or {}
    local cam = snapshot.camera or {}
    local sys = snapshot.system or {}

    -- adjust follow distance if traffic dense or low confidence .. 
    if (cam.confidence < 0.6 or lidar.confidence > 0.6) then 
        params.follow_distance = math.max(params.follow_distance, 25.0)
    else 
        -- slowly decay toward nominal.. 
        params.follow_distance = params.follow_distance - 0.1 
        if params.follow_distance < 15.0 then params.follow_distance = 15.0 end 
    end 
    -- if attention law, lower speed limit.. 
    if snapshot.driver and snapshot.driver.attention and snapshot.driver.attention < params.attention_threshold then 
        params.speed_limit = math.max(5.0, params.speed_limit *0.9)
        safety.alert("Low Attention", {value = snapshot.driver.attention})
    else 
        params.speed_limit = math.min(30.0, params.speed_limit + 0.01)
    end 

    -- persist occasionally.. 
    if sync and sync.put then 
        sync.put("adaptive_policy.params", params)
    end 

    -- emit control hint .. 
    if control and control.send then 
        control.send({cmd = "Set_follow_Distance", value = params.follow_distance})
        control.send({cmd = "Set_speed_LIMIT", value = params.speed_limit})
    end 
    system.log("adaptive policy", {follow_distance = params.follow_distance, speed_limit = params.speed_limit})
end 

return policy 
