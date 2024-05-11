#include "wifi.h"


extern bool run_tls_client_test(const uint8_t *cert, size_t cert_len, const char *server, const char *request, int timeout);


void send_http_post_request(const char* json_data){

    int content_length = strlen(json_data);
    // Prepare the request buffer
    char http_request[1024];  // Ensure this buffer is large enough for your request
    snprintf(http_request, sizeof(http_request), TLS_CLIENT_HTTP_REQUEST, content_length, json_data);

    bool pass = run_tls_client_test(NULL, 0, TLS_CLIENT_SERVER, http_request, TLS_CLIENT_TIMEOUT_SECS);
    if (pass) {
        printf("Test passed\n");
        
    } else {
        printf("Test failed\n");
    }

}