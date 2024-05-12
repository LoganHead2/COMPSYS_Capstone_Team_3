#include "wifi.h"


extern bool run_tls_client_test(const uint8_t *cert, size_t cert_len, const char *server, const char *request, int timeout);


void connect_to_wifi() {
    if (cyw43_arch_init()) {
        printf("failed to initialise\n");
        
        
    }
    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect\n");
        
    }
}

void disconnect_to_wifi() {
    cyw43_arch_disable_sta_mode();	
    // printf("disconnect!!\n");
    
}

void send_http_post_request(const char* json_data){

    int content_length = strlen(json_data);
    // Prepare the request buffer
    char http_request[sizeof(TLS_CLIENT_HTTP_REQUEST) + 100];  // Ensure this buffer is large enough for your request
    snprintf(http_request, sizeof(http_request), TLS_CLIENT_HTTP_REQUEST, content_length, json_data);

    bool pass = run_tls_client_test(NULL, 0, TLS_CLIENT_SERVER, http_request, TLS_CLIENT_TIMEOUT_SECS);
    if (pass) {
        printf("Test passed\n");
        
    } else {
        printf("Test failed\n");
    }

}