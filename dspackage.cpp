#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

struct Node{

struct Node* left;
struct Node* right;
char data[ 100 ];
int leaf;
int length;

};

int i = 0 , last = 1 , strlength = 0 , start = 1 , checkln = 0 ,substrng = 0;
char str1[ 50 ],str2[ 50 ],arr[ 100 ];
struct Node* current1 = new Node;
struct Node* current = new Node;

void checkLength( struct Node* root )
{
            if( root != NULL )
            {
            checkLength( root->left );

            if( root->left == NULL && root->right == NULL && root->leaf == 1)
            checkln +=  root->length;
            checkLength( root->right );
            }
}


struct Node* join_strings( char* s1 , char* s2 ){

    struct Node* y = new Node;
    struct Node* x=new Node;
    struct Node* z=new Node;
    strcpy(x->data,s1);
    x->left=NULL;
    x->right=NULL;
    x->leaf=1;
    x->length = strlen(s1);

    strcpy(z->data,s2);
    z->left=NULL;
    z->right=NULL;
    z->length = strlen(s2);


    if( strcmp( s2 , "end") == 0 )
    {
        z->leaf = 0;
    }
    else
    {
        z->leaf=1;
    }
    y->left = x;
    y->right = z;
    y->leaf=0;
    y->length = x->length;
    return (y);

}

struct Node* join_pointers( struct Node* s1 , struct Node* s2 )
{

    struct Node* y1 = new Node;
    y1->left = s1;
    y1->right = s2;
    current = s1;
    checkLength( s1);
    y1->length = checkln;
    checkln = 0;
    y1->leaf = 0;
    return y1;

};

void substring( struct Node* root , int str , int m)
{
    if( m == 0 )
        {
            substrng = str;
        }
    if( root->left != NULL && root->right != NULL )
    {
        if( substrng > root->length)
        {
                substrng = substrng - root->length;
                substring( root->right , substrng , 1);
        }
        else
        {
            substring( root->left , substrng , 1);
        }
    }
    else
    {
        cout<<"THE SUB STRING IS "<<root->data;
    }
}


void read_man( )
{

    int c , j;
    char a[ 100 ] , b[ 100 ];
    if( i > strlength)
        { last = 0;
        }
    else
        {
            for( j = 0  ; arr[ i ] != 32 && i < strlength; i++ , j++ )
            {
                a[ j ] = arr[ i ];
            }
            a[j]='\0';
            strcpy( str1 , a );
            i++;

            if( i > strlength )
            {
                strcpy(str2 , "end");
                last = 0;
            }
            else
            {
                for( j = 0 ; arr[ i ] != 32 && i < strlength ; i++ , j++ )
                {
                    b[ j ] = arr[ i ];
                }
                b[ j ] = '\0';
                strcpy( str2 , b );
                i++;
            }
    }
}

void insertNode(  )
{

    struct Node* dummy  = new Node;
    struct Node* dummy1  = new Node;
    struct Node* parent  = new Node;
    struct Node* parent1 = new Node;

    if( start == 1 )
        {
                 read_man();
                 parent = join_strings( str1 , str2 );
                 read_man();
                 dummy = join_strings( str1 , str2 );
                 dummy1 = join_pointers( parent , dummy );
                 current1 = dummy1;
                 start = 0;
        }

    if( i < strlength )
    {
            if( last != 0 )
            {
                read_man();
                parent1 = join_strings( str1 , str2 );
                parent = join_pointers( current1 , parent1 );
                current1 = parent;
                insertNode();
            }
        }

}

void leaf(struct Node* root)
{
    if(root)
    {
        leaf(root->left);
        if( root->left == NULL && root->right == NULL && root->leaf == 1)
            cout<<root->data<<" ";
        leaf(root->right);
    }
}

void delete_word(struct Node* root , char* searchd  )
{
    int y;
    if(root)
    { delete_word(root->left , searchd  );

            if( strcmp( root->data , searchd ) == 0)
            {
                    root->leaf = 0;
            }
            else
            {
                 cout<<root->data<<" ";
            }

        delete_word(root->right  , searchd );
       }
}


void find_replace( struct Node* root , char* searchd , char* replacd  )
{
    int y;
    if(root)
    {
        find_replace(root->left , searchd , replacd  );

            if( strcmp( root->data , searchd ) == 0)
            {
                strcpy( root->data , replacd );
            }
            if(strcmp(root->data,"end")!=0)
                cout<<root->data<<" ";

        find_replace(root->right  , searchd , replacd );
    }

}
int flag=0;

bool isSearch( struct Node* root , char* temp )
{
    if( root )
    {
        isSearch(root->left , temp );

            if( strcmp( root->data , temp ) == 0)
              {
                    flag=1;
                    return true;
              }

        isSearch(root->right  , temp );
    }
    if(flag==0)
        return false;
}

int main()
{
    cout<<"\n\n\n\n\n\n\n\n\t\t\tTEXT EDITOR USING ROPE ";
    Sleep(1300);
    struct Node* root = new Node;
    int choice ,choice1, ind ;
    char a[ 10 ] , b[ 10 ];
    system("cls");
        cout<<"\n ENTER THE PARAGRAPH\n";
        scanf(" %[^\n]s",arr);
        strlength = strlen( arr );
        insertNode();
        root = current1;
        cout<<endl;
    do{
        system("cls");
        cout<<"\n\n\n\t\t\t\tMENU";
        cout<<"\n\n\t\t\t1. FIND STRING BY INDEX  \n\t\t\t2. FIND AND REPLACE \n\t\t\t3. DELETE \n\t\t\t4. PRINT \n\nEnter your choice: ";
        cin>>choice;
        system("cls");
        switch( choice )
        {
        case 1:
                    system("cls");
                    cout<<"\n ENTER THE INDEX TO FIND THE STRING:";
                    cin>>ind;
                    system("cls");
                    substring( root , ind , 0);
                    break;


        case 2:
                    system("cls");
                    cout<<"\nENTER WORD TO SEARCH FOR : ";
                    cin>>a;
                    cout<<"\nREPLACE WITH : ";
                    cin>>b;
                    isSearch(root,a);
                    if( isSearch(root,a) )
                        find_replace( root , a , b );
                    else
                        cout<<"\nNot in file..!!\n";
                    break;

        case 3:
                    system("cls");
                    cout<<"\nENTER THE WORD TO BE DELETED\n";
                    cin>>a;
                    if( isSearch(root,a) )
                    {
                        system("cls");
                        delete_word( root , a);
                        system("cls");
                        leaf( root );
                    }
                    else
                    {
                        system("cls");
                        cout<<"THE "<<a<<" NOT IN THE FILE";
                    }
                    cout<<endl;
                    break;

        case 4:
                    system("cls");
                    leaf( root );
                    cout<<endl;
                    break;

        default:
                    cout<<"\nINVALID OPTION";
        }
        cout<<"\n \n 1 - CONTINUE \n 0 - EXIT";
        cin>>choice1;

    }while( choice1 );
return 0;
}


