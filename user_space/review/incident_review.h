#ifndef INCIDENT_REVIEW_H 
#define INCIDENT_REVIEW_H

typedef enum{
    INCIDENT_MINOR, 
    INCIDENT_MAJOR, 
    INCIDENT_CRITICAL
} incident_severity_t; 

int review_incident
(
    const char *incident_id, 
    incident_severity_t severity, 
    const char *summary 
); 

#endif 