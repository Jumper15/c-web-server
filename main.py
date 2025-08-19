import _module

print("hello")
sockfd = _module.server_config(3001)
[newsockfd, message] = _module.run_server(sockfd)
response = _module.send_response(newsockfd, "MESAGE")
print(sockfd, newsockfd, message, response)
