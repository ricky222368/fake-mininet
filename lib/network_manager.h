#ifndef __NETWORK_MANAGER__
#define __NETWORK_MANAGER__

#include <iostream>

#include "vertex.h"
#include "switch.h"
#include "host.h"
#include "edge.h"
#include "hash.h"

class NetworkManager
{
public:
    NetworkManager();
    NetworkManager(int tablesize);
    ~NetworkManager();
    int add_vertex(Vertex *v);
    void add_edge(Edge *e);
    // print
    void print_all_v(); // all vertices
    void print_all_e(); // all edges
    // between 2 vertex
    void connect(std::string hname, std::string tname);
    void disconnect(std::string hname, std::string tname);
    int connected(std::string hname, std::string tname);
    // setlink
    void setlink(std::string hname, std::string tname, int mode, unsigned int val);
    // switch/host name (auto increment)
    std::string get_sw_name();
    std::string get_h_name();
    // clear
    void clear();

    // For API
    int add_switch(std::string name);
    int add_switch();   // using get_sw_name method
    Switch *create_switch();
    Switch *create_switch(std::string);
    int add_host(std::string name);
    int add_host();
    Host *create_host();
    Host *create_host(std::string);
    void linkup(Vertex *head, Vertex *tail);
    void linkdown(Vertex *head, Vertex *tail);
    Vertex *get_all_nodes();
    Vertex *get_node(std::string name);

    // member
    Vertex **vlist;
    Edge *elist;
    int tablesize;
    int switch_num;
    int host_num;
};

#endif