#ifndef TLS_CLIENT_H
#define TLS_CLIENT_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// https://capstoneapi.danielmartinez.co.nz/api/data
// https://api.alphaesia.xyz/scales/ecd2d9cd-8aa3-44be-92f1-2245c5567edf/most_recent_reading
// https://api.alphaesia.xyz/scales/3c4c3640-c59d-409f-9755-30c09133b6ec/most_recent_reading
// #define TLS_CLIENT_SERVER        "api.alphaesia.xyz"
// #define TLS_CLIENT_HTTP_REQUEST  "POST /api/data HTTP/1.1\r\n" \
//                                  "Host: " TLS_CLIENT_SERVER "\r\n" \
//                                  "Content-Type: application/json\r\n" \
//                                  "Content-Length: %d\r\n" \
//                                  "Connection: close\r\n" \
//                                  "\r\n" \
//                                  "%s"

// #define TLS_CLIENT_TIMEOUT_SECS  15

#define TLS_CLIENT_SERVER        "api.alphaesia.xyz"
#define TLS_CLIENT_HTTP_REQUEST  "POST /scales/3c4c3640-c59d-409f-9755-30c09133b6ec/most_recent_reading HTTP/1.1\r\n" \
                                 "Host: " TLS_CLIENT_SERVER "\r\n" \
                                 "Content-Type: application/json\r\n" \
                                 "Content-Length: %d\r\n" \
                                 "Connection: close\r\n" \
                                 "\r\n" \
                                 "%s"

#define TLS_CLIENT_TIMEOUT_SECS  15


extern bool run_tls_client_test(const uint8_t *cert, size_t cert_len, const char *server, const char *request, int timeout);
void connect_to_wifi();
void disconnect_to_wifi();
void send_http_post_request(const char* json_data);

#endif  // TLS_CLIENT_H