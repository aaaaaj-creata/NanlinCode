//#include "select.hpp"
#include "epoll.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("usage: ./main ip port\n");
        return -1;
    }
    std::string ip = argv[1];
    int port = std::stoi(argv[2]);
    TcpSocket lst_sock;

    CHECK_RET(lst_sock.Socket());
    CHECK_RET(lst_sock.Bind(ip, port));
    CHECK_RET(lst_sock.Listen());
    lst_sock.SetNonBlock();
    //Select s;
    Epoll s;
    s.Add(lst_sock);
    while(1) {
        std::vector<TcpSocket> list;
        bool ret = s.Wait(&list);
        if (ret == false) continue;
        for (auto sock : list) {//直接对就绪的描述符进行操作
            if (sock.GetFd() == lst_sock.GetFd()) {//判断就绪的描述符是否是监听套接字
                //监听套接字就绪了
                TcpSocket new_sock;
                bool ret = lst_sock.Accept(&new_sock);
                if (ret == false)continue;
                new_sock.SetNonBlock();
                s.Add(new_sock);//将新建的套接字也添加监控
            }else {
                //普通的通信套接字就绪了
                std::string buf;
                if (sock.Recv(&buf) == false) {
                    s.Del(sock);
                    sock.Close();
                    continue;
                }
                std::cout << "client say: " << buf << std::endl;
                std::cout << "server say ";
                std::cin >> buf;
                if (sock.Send(buf) == false) {
                    s.Del(sock);
                    sock.Close();
                }
            }
        }
    }
    lst_sock.Close();
    return 0;
}
