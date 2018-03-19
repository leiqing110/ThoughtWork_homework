  
  #include "plane.h"


   int main () 
   {  
       string sline; //存储每一行
       plane p1;
       int id;
       string s1;
       int x,y,z,x1=0,y1=0,z1=0;
      
       int num = 0;
       ifstream in("plane.txt");  
       if (! in.is_open())  
       {
        cout << "Error opening file"; 
        exit (1);
       }  
       
       while(1)
       {
         while(getline(in,sline))    //按行读取到字符串变量s中
         { 
        
                 istringstream sin(sline);
                 sin>>s1>>x>>y>>z>>x1>>y1>>z1;
                 p1.set(s1,num,x,y,z);
                 p1.setx1y1z1(num,x1,y1,z1);
                 p1.location(num,x1,y1,z1);
                 x1 = 0;
                 y1 = 0;
                 z1 = 0;
                 num++;
          } 
          cout<<"指定消息ID：";
          cin>>id;
          if(p1.getstate(id,num))
          {
             num--;
             if(id >num)
             {
                cout<<"Cannot find "<<id<<endl;
             }
             else
             {
                 p1.display(id);
             }
             num++;
          }
          
        } 
        in.close();
         return 0;
   } 