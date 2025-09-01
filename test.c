#include "server_launch.c"

int main()
{
     int port = 30001;
     char* route = "/foo/bar";
     char* method = "GET";
     char* res_file_name = "homepage.html";

     server_launch(port, route, method, res_file_name);
}