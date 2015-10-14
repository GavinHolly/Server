/** 
2 * 
3 *  File Name: Common.hpp 
4 *  brief: 
5 *  Create Time: 2015年10月13日 17:47 
6 *  Author Gavin 
7 */  
#ifndef COMMON_H
#define COMMON_H
namespace Comon
{
ifdef WIN_32
typedef SOCKET GAVIN_SOCKET
#else
  typedef int GAVIN_SOCKET
#endif
  inline bool SetNoDelay(GAVIN_SOCKET fd)
  {
  #ifndef WIN_32
    int isTrue = true?1:0;
    //                  IPPROTO_TCP表示在那个层
    //level：选项定义的层次；支持SOL_SOCKET、IPPROTO_TCP、IPPROTO_IP和IPPROTO_IPV6。
    //获取或者设置与某个套接字关联的选项
    return setsockopt(fd,IPPROTO_TCP,TCP_NODELAY,(char*)&isTrue,sizeof(isTrue)) == 0;//TCP_NODELAY BOOL 禁止发送合并的Nagle算法。
  #else
    int fd_flags;
    bool isTrue = TRUE ;
    if(setsockopt(fd,IPPROTO_TCP,(char*)&isTrue,sizeof(isTrue)) != 0)
    {
      return false;
    }
    fd_flags = ::fcntl(fd)
  }
}
#endif
