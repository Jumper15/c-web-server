import _module

print("hello")
sockfd = _module.server_config(3001)
[newsockfd, message] = _module.run_server_tcp(sockfd)
response = _module.send_from_file(newsockfd, "file.txt")
print(sockfd, newsockfd, message, response)
