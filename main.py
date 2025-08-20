import _module

print("hello")
sockfd = _module.server_config(3001, "SOCK_DGRAM")
message = _module.run_server_udp(sockfd)
# response = _module.send_from_file(newsockfd, "file.txt")
print(sockfd, newsockfd, message, response)
