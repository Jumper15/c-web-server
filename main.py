import _module
import time
import asyncio

async def run(sockfd):
    sockfd = await _module.server_config(3001)
    print(sockfd)
    newsockfd = await _module.run_server(sockfd)
    print(newsockfd)
    response = _module.send_response(newsockfd)
    print(response)
    return 0

print("hello world")
run(3001)

# print("hello")
# sockfd = _module.server_config(3001)
# message = _module.run_server(sockfd)
# print(message)

# def callback(string):
#     return string

# path = _module.add_route("string", callback)
# print(path)