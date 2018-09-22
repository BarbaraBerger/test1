#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include<netinet/in.h>

#include<fcntl.h>


//il faut rajouter l'option rebouting

int do_socket(){
  int sockfd;
  int yes=1;
  //create the socket
  sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  printf("%d\n",sockfd);
  //check for validity

  if (sockfd == -1)
  {
      perror("socket");
      exit(EXIT_FAILURE);
  }
  else
    return(sockfd);
}



//Je comprends rien à cette fonction !!!!
/*void get_addr_info(const char * address, const char* port, struct addrinfo** res){
  int status;
  struct addrinfo hints, p;

  memset(&hints,0,sizeof(hints));
  hints.ai_family=AF_INET;
  hints.ai_socktype=SOCK_STREAM;

  status= getaddrinfo(address, port, hints,res);

}

void do_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
  int res = connect(sockfd,addr,addrlen);
  if (res !=0){
    fprintf(stderr,"Echec connexion\n");
    return 1;
  }
}
*/
void readline(int socket){
  /*char *texte_msg;
  scanf("%s",&texte_msg);
  printf("%s\n",&texte_msg);*/
  char *texte;
  scanf("%s",&texte);

  int sent = 0;
  do{
    sent += write(socket,&texte + sent, sizeof(texte) - sent);
  }while (sent != sizeof(texte));

  int tens = 0;
  do{
    tens += read(STDIN_FILENO, socket + tens, sizeof(texte) - tens);
  }while (tens != sizeof(texte));




  //write(socket, &texte, sizeof(texte));
  //read()
}
/*
  struct sockaddr_in sin;
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = 0;
}
*/
int main(int argc,char** argv)
{


    if (argc != 3)
    {
        fprintf(stderr,"usage: RE216_CLIENT hostname port\n");
        return 1;
    }


//get address info from the server
//get_addr_info()


//get the socket
int s;
s = do_socket();
printf("s=%d\n",s);

//connect to remote socket
/*do_connect(s,)//a completer avec get @


*/
//get user input
readline(s);

//send message to the server
//handle_client_message()


    return 0;


}
