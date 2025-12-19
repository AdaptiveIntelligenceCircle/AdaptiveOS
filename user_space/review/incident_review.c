#include <stdio.h>
#include "incident_review.h"

int review_incident(
    const char *incident_id , 
    incident_severity_t severity, 
    const char *summary
)
{
    if (!incident_id || !summary)
    return -1; 

    printf("Review Incident Review\n"); 
    pritnf("ID : %s\n", incident_id); 

    printf("Severity : %d\n", severity); 
    printf("Summary : %s\n", summary); 

    // results feed governance and trust system.. 
    return 0; 
}