
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>
#include <stdio.h>

// for g++
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <functional>
#include <vector>
#include <unordered_set>

#include "addSalt.hpp"

#define MAC_STRING_LENGTH 13

int getMac(const char *iface, char* mac)
{
  struct ifreq s;
  int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);

  std::strcpy(s.ifr_name, iface);
  if (fd >= 0 && mac && 0 == ioctl(fd, SIOCGIFHWADDR, &s))
  {
    int i;
    for (i = 0; i < 6; ++i)
      snprintf(mac+i*2,MAC_STRING_LENGTH-i*2,"%02x",(unsigned char) s.ifr_addr.sa_data[i]);
  }
  else
  {
    perror("malloc/socket/ioctl failed");
    exit(1);
  }
  return (0);
}


static std::vector<std::string> GLOBAL_machineMacAddr = 
{
  "0~c!c@4#7$a%3^4&f*8(f)6_" 
};

bool checkComputerMacAddr(){
    char macAddr[MAC_STRING_LENGTH];

    getMac("enp4s0f0", macAddr );
    
    std::string macStr = std::string(macAddr);

    std::hash<std::string> strHash ; 
    std::unordered_set<std::size_t> machineMacAddrSet ; 
    for (auto item: GLOBAL_machineMacAddr){
        machineMacAddrSet.insert( strHash( item ) ) ; 
    }

    addSalt(macStr);
    auto thisMachineHash = strHash(macStr) ; 
    if ( machineMacAddrSet.count(thisMachineHash) > 0 ){
        return true;
    }

    return false ;
}

// std::string testStr = "0cc47a34f8f6";
void startProtectedProgram(){
    std::cout << " Starting Protected Program " << std::endl;
}

int main()
{

  if (checkComputerMacAddr())  {
      std::cout << " Good! Passed the MAC Address Check. " << std::endl;
  }else{
      std::cout << " Bad " << std::endl;
      std::cout << " Please add your salt MAC Address to GLOBAL_machineMacAddr" << std::endl;
      return -1 ; 
  }

  startProtectedProgram() ;


  return 0 ; 

}
