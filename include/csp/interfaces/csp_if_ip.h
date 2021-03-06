/**
 * CSP Internet Protocol Interface Header 
 * Stephen Floers
 * 2019/02/09
 */

#ifndef _CSP_IF_IP_H
#define _CSP_IF_IP_H

#ifdef __cplusplus
extern "C" {
#endif 

#include <stdint.h>

#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#include <csp/csp.h>
#include <csp/csp_interface.h>
#include <csp/arch/csp_thread.h>

// ***** IP interface definitions 
#define CSP_IF_IP_MAX_BUF_SIZE 1500 /* IP IF MTU */

// ***** IP interface global objects 
extern csp_iface_t csp_if_ip;
int csp_if_ip_fd;
const char* csp_ip_tx_addr;
uint16_t csp_ip_tx_port;
uint16_t csp_ip_rx_port;

// ***** IP interface configuration struct 
typedef struct {
    const char* tx_addr; // IP address to send data to
    uint16_t tx_ip_port; // IP (BSD socket) port to send to 
    uint16_t rx_ip_port; // IP (BSD socket) port to receive data on
} csp_ip_config_t;

// Initialize the IP interface and start the IP server 
int csp_ip_init(csp_ip_config_t config);

// IP Server task 
csp_thread_handle_t csp_ip_server_handle;
csp_thread_return_t csp_ip_server(void* params);

#ifdef __cplusplus
}
#endif 

#endif 