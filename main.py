import _module
# import importlib
# importlib.reload(_module)

print("hello")
sockfd = _module.server_config(3001)
print(sockfd)
res = _module.server_launch(sockfd)
# message = _module.run_server_udp(sockfd)
# # response = _module.send_from_file(newsockfd, "file.txt")
# print(sockfd, newsockfd, message, response)
