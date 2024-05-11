#ifndef TLS_CLIENT_H
#define TLS_CLIENT_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// Update these with appropriate server details
#define TLS_CLIENT_SERVER        "capstoneapi.danielmartinez.co.nz"
#define TLS_CLIENT_HTTP_REQUEST  "POST /api/data HTTP/1.1\r\n" \
                                 "Host: " TLS_CLIENT_SERVER "\r\n" \
                                 "Content-Type: application/json\r\n" \
                                 "Content-Length: %d\r\n" \
                                 "Connection: close\r\n" \
                                 "\r\n" \
                                 "%s"

#define TLS_CLIENT_TIMEOUT_SECS  15

// Function declarations
extern bool run_tls_client_test(const uint8_t *cert, size_t cert_len, const char *server, const char *request, int timeout);

void send_http_post_request(const char* json_data);

#endif  // TLS_CLIENT_H