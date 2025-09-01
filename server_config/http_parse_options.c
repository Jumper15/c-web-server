// #include "_module.h"

struct LinkedList* http_parse_options(struct http_request_options* res_opts)
{
     // only method handling, no route handling yet
     // dictionary storing routes and methods
     struct LinkedList* res_dict = ll_constructor();
     struct Node* res_node = node_constructor(res_opts->method, res_opts->res_file_name, NULL);
     addNode(res_dict, res_node, res_dict->ll_len);

     return res_dict;
}