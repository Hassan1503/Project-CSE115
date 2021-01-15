#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
///global variable
struct team  ///create structure data type
{
    char name[50];
    char position[50];
    int match;
    char nationality[50];
}player,player_no[100];
int i,j,k,x;///global variable
///prototype all function.
int admin(struct team player_no[],int i);
void user(struct team player_no[],int i);
int edit(struct team player_no[],int x);///edit no 239
int delet(struct team player_no[],int i);///delet no 147
int add(struct team player_no[],int i);///add no 164
void search(struct team player_no[],int x);///search no 273
void show(struct team player_no[],int x);///show no 186
void end(struct team player_no[],int x);
///file pointer.
FILE* input;
FILE* output;
int main()///main function.
{
    start();
    menu();
    ///end(player_no,i);
    printf("Thanks for using the software.");
    printf("\n\n\nPOWERED BY ACROMATIC SOFTWARE DEVELOPMENT COMPANY......");
};
void start()///Begining designing function.
{
    printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t@           WELL COME              @\n");
    printf("\t\t@                                  @\n");
    printf("\t\t@        To Player Data            @\n");
    printf("\t\t@                                  @\n");
    printf("\t\t@     ##        #**#**#            @\n");
    printf("\t\t@     ##        #  #  #            @\n");
    printf("\t\t@     ##        #  #  #            @\n");
    printf("\t\t@   ######      #  #  #      ***   @\n");
    printf("\t\t@   ######      #  #  #     *****  @\n");
    printf("\t\t@   ######      #  #  #     *****  @\n");
    printf("\t\t@   ######      #  #  #      ***   @\n");
    printf("\t\t@   ######      #  #  #            @\n");
    printf("\t\t@   ######      #  #  #            @\n");
    printf("\t\t@   ######      #  #  #            @\n");
    printf("\t\t@ -------------------------------- @\n");
    printf("\t\t@          OF CRICKET              @\n");
    printf("\t\t@                                  @\n");
    printf("\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}
void menu()///choosen admin user function.
{
        int u;
    int i=0;
    char ch;
    printf("\n1.ADMIN\n2.USER\n3.End\n");
    printf("press Number:");
    scanf("%d",&u);
    struct team player_no[100];
    char data[10]="player.txt";
    input=fopen(data,"r");
    while(!feof(input))
    {
        fgets(player.name,50,input);
        fgets(player.position,50,input);
        fscanf(input,"%d",&player.match);
        fgetc(input);
        fgets(player.nationality,50,input);
        player_no[i]=player;
        i++;
    }
    strcat(player_no[i-1].nationality,"\n");
fclose(input);
///for(j=0;j<i;j++){
    ///printf("Name: %s",player_no[j].name);
    ///printf("Position: %s",player_no[j].position);
    ///printf("Match No: %d\n",player_no[j].match);
    ///printf("Nationality: %s",player_no[j].nationality);
    ///printf("\n");}

    switch(u)
    {
    case 1:///admin profile open
       {
        printf("You choose the ADMIN profile.\n");
        printf("Enter Password:");
        int j=0,Continue=1;
        char a,y[20],x[]="hassan";
        while (Continue)
        {
            a=getch();
            if (a== 13)
            {
                Continue=0;
                y[j]=0;
            }
            else
            {
                y[j]=a;
                printf("*");
                j++;
            }
        };
        if(strcmp(x,y)==0)
        {
           printf("\n\n\t\t\tWelcome to the ADMIN profile.\n\n\n");
           i=admin(player_no,i);
           end(player_no,i);
        }
        else///don't match password
            {
                printf("\nINVALID PASSWORD.\n");
                menu();
            }
        break;///admin profile close
       }
    case 2:///user profile open
       {
        printf("\n\n\t\t\tWelcome to the USER profile\n\n\n");
        user(player_no,i);
        end(player_no,i);
        break;
       }
    case 3:
        {
            end(player_no,i);
            return 0;
        }///user profile close
    default:///
       {
         printf("SORRY!!!!\nYOU PRESS INVALID INPUT.\n");
         end(player_no,i);
         menu();
         break;
       }
    }
}
int admin(struct team player_no[],int i)///admin function.
{
///enter the admin profile
            ///printf("admin");
            printf("What do u want?\n");
            printf("1.Edit\n2.Delet\n3.Add\n4.Return\n5.End.\n");
            int n;
            printf("Press Number:");
            scanf("%d",&n);
            switch(n)
            {
            case 1:///for edit
                {
                    ///printf("edit\n");
                    i=edit(player_no,i);
                    i=admin(player_no,i);
                    end(player_no,i);
                    break;
                }
            case 2:///for delet
                {
                    ///printf("delet\n");
                    i=delet(player_no,i);///prb here
                    i=admin(player_no,i);
                    end(player_no,i);
                    break;
                }
            case 3:///for add
                {
                    ///printf("%d\n",i);
                    i=add(player_no,i);
                    i=admin(player_no,i);
                    end(player_no,i);
                    break;
                }
            case 4:
                {
                    menu();
                    break;
                }
            case 5:
                {
                    break;
                }
            default:
               {
                    printf("SORRY!!!!\nYOU PRESS INVALID INPUT.\n");
                    break;
               }
            }
    return i;
}
void end(struct team player_no[],int x)///to save data before closing program function.
{
    ///printf("function x=%d",x);
    char output_txt[20]="player.txt";///change the file location.
    output=fopen(output_txt,"w");///write data file.
for(j=0;j<x;j++)
{
    ///printf("\nafter %d.x=%d\n",j+1,x);
    fprintf(output,"%s",player_no[j].name);
    fprintf(output,"%s",player_no[j].position);
    fprintf(output,"%d\n",player_no[j].match);
    fprintf(output,"%s",player_no[j].nationality);
}
fclose(output);
///for(j=0;j<x;j++){
   ///printf("Name: %s",player_no[j].name);
    ///printf("Position: %s",player_no[j].position);
    ///printf("Match No: %d\n",player_no[j].match);
    ///printf("Nationality: %s",player_no[j].nationality);
    ///printf("\n");}
}
/// here start call function delet=210,add=231,show=346,edit=255,search=415.
int delet(struct team player_no[],int i)///for delet function.
{
    printf("Which Player data u want to delet.\n");
    printf("Enter Player Name:");
    getchar();
    gets(player.name);
    strcat(player.name,"\n");
    for(j=0;j<i;j++)
    {
        if((strcmp(player.name,player_no[j].name))==0)
        {
            for(k=j;k<i;k++)
            {
                player_no[k]=player_no[k+1];
            }
        }
    }
    i--;
    printf("\nDelet your expected Player Data.\n");
    return i;
}
int add(struct team player_no[],int i)///to add function.
{
    ///printf("%d\n",x);
    char name[30];
    printf("Enter Player Name:");
    getchar();
    gets(name);
    strcat(name,"\n");
    strcpy(player.name,"\0");
    ///printf("add:%s",name);
    ///printf("add1:%s",player.name);
    strcat(player.name,name);
    printf("Enter Player Position:");
    scanf("%s",player.position);
    strcat(player.position,"\n");
    printf("Enter Player Match No:");
    scanf("%d",&player.match);
    getchar();
    printf("Enter Player Nationality:");
    scanf("%s",player.nationality);///prb here program doesnt take input.
    ///strcat(player.nationality,"\n");
    printf("\nComplete adding new Player data.\n\n");
    i++;
    player_no[i-1]=player;

    ///printf("name:%s",player_no[i-1].name);
    return i;
}
int edit(struct team player_no[],int x)///to edit function.
{
    printf("Which player data u want to edit.\n");
    printf("Enter Player Name:");
    char name[20];
    int m;
    getchar();
    gets(name);
    strcat(name,"\n");
    for(i=0;i<x;i++)
    {
        if((strcmp(player_no[i].name,name))==0)
            {
               m=i;
            }
    }

    printf("What do u want to edit.\n");
    printf("\n1.Match no\n2.Nationality\n3.Return\n");
    int n;
    printf("Press Number:");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        {
            ///printf("\nm==%d\n",m);
            printf("\nEnter New Match No:");
            scanf("%d",&player_no[m].match);
            printf("Complete adding new data.\n");
            ///printf("\nhere\n");
            break;
        }
    case 2:
        {
            printf("Enter New Nationality:");
            getchar();
            scanf("%s",player_no[m].nationality);
            printf("Complete adding new data.\n");
            break;
        }
    case 3:
        {
            i=edit(player_no,i);
            break;
        }
    default:
        printf("INVALID INPUT.\n");
        i=edit(player_no,i);
        break;
    }
    return x;
}
void user(struct team player_no[],int i)///user function.
{
           /// printf("user");
        ///printf("Welcome to the USER Profile.\n");
        printf("\nwhat do u want?\n");
        printf("1.Show\n2.search\n3.Return\n4.End\n");
        int y;
        printf("Press Number:");
        scanf("%d",&y);
        switch(y)
        {
        case 1:///for show.
            {
                show(player_no,i);
                user(player_no,i);
                break;
            }
        case 2:///for search
            {
                ///printf("search\n");
                search(player_no,i);
                user(player_no,i);
                break;
            }
        case 3:
            {
                menu();
                break;
            }
        case 4:
            {
                break;
            }
        default:
            printf("SORRY!!!!\nYOU PRESS INVALID INPUT.\n");
            break;
        }
}
void show(struct team player_no[],int x)///to show player data..
{
    int n;
    ///printf("\nx=%d\n",x);
    char country[20],player[50];
    printf("\nwhat do u want to see?\n");
    printf("1.Player of the Country.\n2.Specific Player Data.\n3.Return\n");///ask to user
    printf("Press Number:");
    scanf("%d",&n);
    switch(n)
    {
    case 1:///if user want to see player of the country.
        {
            int j=0;
            printf("Which player list of the country you want to see.\n");
            printf("Enter Country Name:");
            getchar();
            gets(country);
            strcat(country,"\n");
            printf("\t\tPlayer List of the %s\n\n",country);
            for(i=0;i<x;i++)
            {
                    ///printf("\nx=%d\n",x);
                    int l=strcmp(player_no[i].nationality,country);///prb here strcmp function doesnt work properly.
                    if(strcmp(player_no[i].nationality,country)==0)
                    {
                       ///printf("l==%d\n",l);
                       ///printf("hlw\n");
                       j++;
                       printf("%d.%s",j,player_no[i].name);
                       ///printf("\n%d\n",i);
                    }
            }
            break;
        }
    case 2:///if user want to see specific player data.
        {
            char player[50];
            int m;
            printf("Enter player name:");
            getchar();
            gets(player);
            strcat(player,"\n");
            printf("\n");
            for(i=0;i<x;i++)
            {
                int l=strcmp(player,player_no[i].name);///prb here strcmp function doesnt work properly.
                if((strcmp(player_no[i].name,player))==0)
                {
                  printf("\t\tHere the your choosen Player Data\n");
                  printf("\nName:%s",player_no[i].name);
                  printf("Position:%s",player_no[i].position);
                  printf("Match no:%d\n",player_no[i].match);
                  printf("Nationality:%s",player_no[i].nationality);
                  break;
                }
            }
            break;
        }
    case 3:
        {
            user(player_no,i);
            break;
        }
    default:///press invalid number.
        printf("SORRY!!!!\nYOU PRESS INVALID INPUT.\n");
        break;
        }
}
void search(struct team player_no[],int x)///to search function.
{
    printf("Which Catagory Player u want to search.\n");
    printf("Enter Position:");
    char position[20];
    int m;
    int j=0;
    getchar();
    gets(position);
    strcat(position,"\n");
    printf("\t\tList of the %s\n\n",position);
    for(i=0;i<x;i++)
    {
        if((strcmp(player_no[i].position,position))==0)
        {
            j++;
            printf("%d.%s",j,player_no[i].name);
            printf("  Country:%s",player_no[i].nationality);

        }
        ///break;
    }
}
