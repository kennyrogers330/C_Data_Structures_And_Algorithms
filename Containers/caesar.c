#include<stdio.h>
void encrypt()
{
char message[100], ch;
int i, key;
printf("Enter a message to encrypt: ");
//gets(message);
scanf("%s", message);
printf("Enter key: ");
scanf("%d", &key);
for(i = 0;  message[i] != '\0';  ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch + key;
if(ch > 'z'){
ch = ch - 'z' + 'a' - 1;
}
message[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch + key;
if(ch > 'Z'){
ch = ch - 'Z' + 'A' - 1;
}
message[i] = ch;
}
}
printf("Encrypted message: %s", message);
}

void decrypt()
{
    char message[100], ch;
int i, key;
printf("Enter a message to decrypt: ");
//gets(message);
scanf("%s", message);
printf("Enter key: ");
scanf("%d", &key);
for(i = 0; message[i] != '\0'; ++i){
ch = message[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch - key;
if(ch < 'a'){
ch = ch + 'z' - 'a' + 1;
}
message[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch - key;
if(ch < 'A'){
ch = ch + 'Z' - 'A' + 1;
}
message[i] = ch;
}
}
printf("Decrypted message: %s", message);
}

int main()
{
    int c;
    do{
        printf("\nChoose: \n 1. encrypt\n 2. Decrypt\n");
        scanf("%d", &c );
        switch(c)
        {
        case 1:
           encrypt();
           break;
        case 2:
           decrypt();
           break;
        case 0:
            break;
        default:
            printf("wrong");
        }
    }while(c!=0);
return 0;
}


