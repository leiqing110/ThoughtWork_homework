 #ifndef __PLANE_H__
#define __PLANE_H__
  
   #include<string>
   #include<fstream>  
   #include<stdlib.h>  
   #include<sstream>
   #include"message.h"
   
   using namespace std;

   #define nums 20;
    class plane{
       private:
         string name;
         message msg[20];  //ÏûÏ¢
         bool state ; //×´Ì¬
       public:
         plane()
         { 
            state = 1; 
            name ="plane1";
            for(int i=0;i<10;i++)
            {
                msg[i].msg_id = 0;
                msg[i].x = 0;
                msg[i].y = 0;
                msg[i].z = 0;
            
            }
         }
         bool getstate(int msgid,int num);
         message getMessage(plane &p,int msgid);
         void set(string s,int msgid,int x1,int y1,int z1);
         void location(int msgid,int x1,int y1,int z1);
         void display(int num);
         void setx1y1z1(int msgid,int a,int b,int c);
         void clear(int msgid);
    };

    message plane::getMessage(plane &p,int msgid)
    {
       return  p.msg[msgid];
    }
    void plane::set(string s,int msgid,int x1, int y1,int z1)
    {
        name = s;
        msg[msgid].x = x1;
        msg[msgid].y = y1;
        msg[msgid].z = z1;
    }
    void plane::setx1y1z1(int msgid,int a,int b,int c)
    {
        msg[msgid].x1 = a;
        msg[msgid].y1 = b;
        msg[msgid].z1 = c;
    }

    void plane::location(int msgid,int x1,int y1,int z1)
    {
        msg[msgid].x +=x1;
        msg[msgid].y +=y1;
        msg[msgid].z +=z1;
    }
    bool plane::getstate(int msgid,int num)
    {
        int msgid2 =msgid-1;
       if(msgid>0&&msgid<=(num-1))  //ÐÅºÅID>0
        {
            if(((msg[msgid].x-msg[msgid].x1-msg[msgid2].x1)!= (msg[msgid2].x-msg[msgid2].x1))||((msg[msgid].y-msg[msgid].y1-msg[msgid2].y1)!= (msg[msgid2].y-msg[msgid2].y1))||((msg[msgid].z-msg[msgid].z1-msg[msgid2].z1)!= (msg[msgid2].z-msg[msgid2].z1)))
            {
                cout<<"Error:"<<msgid<<endl;
                return 0;
            }
            else if(name!="plane1")
            {
                cout<<"Error:"<<msgid<<endl;
                return 0;
            }
            else 
                return 1;
        }
        else
            return 1;
    //  }
    }

    void plane::clear(int msgid)
    {
        msg[msgid].x1 = 0;
        msg[msgid].y1 = 0;
        msg[msgid].z1 = 0;
    }
   void plane::display(int num)
    {
      //  for(int i = 0;i<num;i++)
            cout<<name<<" "<< num<<" "<<msg[num].x<<" "<<msg[num].y<<" "<<msg[num].z<<endl;
    }
 
    #endif