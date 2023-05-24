#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <iterator>
#include <stack>
 #include <unistd.h>
 #include "map.hpp"
#include <map>
 
void max_size()
{
        std::cout << "\n\n\t\t\t\t\t  ************** max_size() ************* \t\t\t\t\t\n\n" << std::endl; 
   
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;

    ft::vector<int> v1;
    ft::vector<long> v2;
    ft::vector<char> v3;
    ft::vector<std::string> v4;
    ft::vector<unsigned int> v5;
    ft::vector<long long> v6;
    ft::vector<unsigned char> v7;
    std::cout << v1.max_size() << std::endl;
    std::cout << v2.max_size() << std::endl;
    std::cout << v3.max_size() << std::endl;
    std::cout << v4.max_size() << std::endl;
    std::cout << v5.max_size() << std::endl;
    std::cout << v6.max_size() << std::endl;
    std::cout << v7.max_size() << std::endl;
            std::cout << "\t\t\t****** STD vector : *************"  << std::endl;
    std::vector<int> v12;
    std::vector<long> v22;
    std::vector<char> v32;
    std::vector<std::string> v42;
    std::vector<unsigned int> v52;
    std::vector<long long> v62;
    std::vector<unsigned char> v72;
    std::cout << v12.max_size() << std::endl;
    std::cout << v22.max_size() << std::endl;
    std::cout << v32.max_size() << std::endl;
    std::cout << v42.max_size() << std::endl;
    std::cout << v52.max_size() << std::endl;
    std::cout << v62.max_size() << std::endl;
    std::cout << v72.max_size() << std::endl;
}
 

void erase()
{
        std::cout << "\n\n\t\t\t\t\t  ************** erase ************* \t\t\t\t\t\n\n" << std::endl; 
     {
            std::cout << "\t\t\t****** STD vector : *************"  << std::endl;

        ft::vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout<< "size : " << v1.size() << std::endl;
        std::cout << "erase  : " << *(v1.erase(v1.end()- 2)) << std::endl;
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
     }
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;
     {
        ft::vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout<< "size : " << v1.size() << std::endl;
        std::cout << "erase  : " << *(v1.erase(v1.end()- 2)) << std::endl;
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
     }
}
void erase_range()
{
            std::cout << "\n\n\t\t\t\t\t  ************** erase_range ************* \t\t\t\t\t\n\n" << std::endl; 

    {
                    std::cout << "\n\t\t\t****** STD vector : *************\n"  << std::endl;
        std::vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        v1.push_back(60);
        v1.push_back(70);
        v1.push_back(80);

        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
        v1.erase(v1.begin(),v1.begin()+5);
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
    }
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;
    {
            ft::vector<int> v1;
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);
        v1.push_back(60);
        v1.push_back(70);
        v1.push_back(80);

        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
        v1.erase(v1.begin(),v1.begin()+5);
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
    }
}


void insert()
{
      std::cout << "\n\n\t\t\t\t\t  ************** insert ************* \t\t\t\t\t\n\n" << std::endl; 

    {
                    std::cout << "\n\t\t\t****** STD vector : *************\n"  << std::endl;
        std::vector<int> v;
        std::cout << *(v.insert(v.end(),20)) << std::endl;
        std::cout << *(v.insert(v.end(),210)) << std::endl;
        std::vector<int>::iterator it = v.insert(v.begin(),7);
        std::cout << *it << std::endl;
        v.insert(v.begin()+2,50);
        std::cout << *(v.insert(v.begin(),60)) << std::endl;
        std::cout << "size : "<<v.size() << "  capacity " << v.capacity() << std::endl; 
        for(size_t i = 0 ; i < v.size(); i++)
            std::cout << v[i] << std::endl;
    }
    {
                            std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;

    ft::vector<int> v;
    std::cout << *(v.insert(v.end(),20)) << std::endl;
    std::cout << *(v.insert(v.end(),210)) << std::endl;
    ft::vector<int>::iterator it = v.insert(v.begin(),7);
    std::cout << *it << std::endl;
    v.insert(v.begin()+2,50);
    std::cout << *(v.insert(v.begin(),60)) << std::endl;
    std::cout << "size : "<<v.size() << "  capacity " << v.capacity() << std::endl; 
    for(size_t i = 0 ; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    }
}
void insert_fill()
{
       std::cout << "\n\n\t\t\t\t\t  ************** insert_fill ************* \t\t\t\t\t\n\n" << std::endl; 

    {
                    std::cout << "\n\t\t\t****** STD vector : *************\n"  << std::endl;
        std::vector<int> v1;
        for(int i = 1 ; i < 20; i++) v1.push_back(i);
        for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        v1.insert(v1.end(),10,12500);
        std::cout << "\nsize : "<< v1.size() << "  capacit " << v1.capacity() <<std::endl;
        for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        std::cout << std::endl;
      
    }
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;
    {
        ft::vector<int> v1;
        for(int i = 1 ; i < 20; i++) v1.push_back(i);
        for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        v1.insert(v1.end(),10,12500);
        std::cout << "\nsize : "<< v1.size() << "  capacit " << v1.capacity() <<std::endl;
        for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        std::cout << std::endl;
     
    }
     
}
void push_back()
{
   std::cout << "\n\n\t\t\t\t\t  ************** push_back ************* \t\t\t\t\t\n\n" << std::endl; 

    {
                    std::cout << "\n\t\t\t****** STD vector : *************\n"  << std::endl;
        std::vector<int> v;
        v.push_back(5);
        for(int i = 8; i < 20 ; i++)
            v.push_back(i);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;

        for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
         
      
    }
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;
    {
         ft::vector<int> v;
        v.push_back(5);
        for(int i = 8; i < 20 ; i++)
            v.push_back(i);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;

        for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
     
    }
}
void pop_back()
{
       std::cout << "\n\n\t\t\t\t\t  ************** pop_back ************* \t\t\t\t\t\n\n" << std::endl; 

  {
                    std::cout << "\n\t\t\t****** STD vector : *************\n"  << std::endl;
        std::vector<int> v;
         for(int i = 1; i < 10 ; i++)
            v.push_back(i);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
         for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
        v.pop_back();
        v.pop_back();
        v.pop_back();
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() << "\t\t\t after 3 pop_back()" <<std::endl;

        for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
         
      
    }
    {
        std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;
         ft::vector<int> v;
         for(int i = 1; i < 10 ; i++)
            v.push_back(i);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
         for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
        v.pop_back();
        v.pop_back();
        v.pop_back();
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() << "\t\t\t after 3 pop_back()" <<std::endl;

        for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << std::endl;
     }
          
     
}

void clear()
{
    
       std::cout << "\n\n\t\t\t\t\t  ************** clear ************* \t\t\t\t\t\n\n" << std::endl; 
            std::cout << "\n\t\t\t****** std vector : *************\n"  << std::endl;
            {
                std::vector<int> v;
                for(int i = 1; i < 20 ; i++)
                    v.push_back(i);
                std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
                for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
                    std::cout << *it << "  " ;
                    v.clear();
                std::cout    << "\n\t\t\t after clear()" <<std::endl;
            std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() << std::endl;
            }

    
    {
                std::cout << "\n\t\t\t****** FT vector : *************\n"  << std::endl;

     ft::vector<int> v;
         for(int i = 1; i < 20 ; i++)
            v.push_back(i);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
        for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
            v.clear();
          std::cout    << "\n\t\t\t after clear()" <<std::endl;
     std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() << std::endl;
    }

      
} 
void resize()
{
     std::cout << "\n\n\t\t\t\t\t  ************** clear ************* \t\t\t\t\t\n\n" << std::endl; 
            std::cout << "\n\t\t\t****** std vector : *************\n"  << std::endl;
    {
        std::cout << "\n\n\nresize 10 with 50" << std::endl;
        std::vector<int> v;
        v.resize(10,50);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
         for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << "\n\n\nresize 2 with 100" << std::endl;
        v.resize(12,100);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
        for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
         std::cout << "\n\n\nresize 4 with 99" << std::endl;
        v.resize(4,99);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
        for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
    }
            std::cout << "\n\t\t\t****** ft vector : *************\n"  << std::endl;
    {
        std::cout << "\n\n\nresize 10 with 50" << std::endl;
        ft::vector<int> v;
        v.resize(10,50);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
         for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << "\n\n\nresize 12 with 100" << std::endl;
        v.resize(12,100);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
        for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
        std::cout << "\n\n\nresize 4 with 99" << std::endl;
        v.resize(4,99);
        std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;
        for(ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << "  " ;
    }
}


void map_insert()
{
    std::cout << "\n\n\t\t\t\t\t  ************** insert() ************* \t\t\t\t\t\n\n" << std::endl;

    std::cout << "\n\t\t\t****** FT map : *************\n" << std::endl;
    ft::map<int, std::string> ft_map;
    ft_map.insert(ft::make_pair(1, "One"));
    ft_map.insert(ft::make_pair(2, "Two"));
    ft_map.insert(ft::make_pair(3, "Three"));

    for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

    std::cout << "\n\t\t\t****** STD map : *************" << std::endl;
    std::map<int, std::string> std_map;
    std_map.insert(std::make_pair(1, "One"));
    std_map.insert(std::make_pair(2, "Two"));
    std_map.insert(std::make_pair(3, "Three"));

    for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}

void map_erase()
{
    std::cout << "\n\n\t\t\t\t\t  ************** erase() ************* \t\t\t\t\t\n\n" << std::endl;

    std::cout << "\n\t\t\t****** FT map : *************\n" << std::endl;
    ft::map<int, std::string> ft_map;
    ft_map.insert(ft::make_pair(1, "One"));
    ft_map.insert(ft::make_pair(2, "Two"));
    ft_map.insert(ft::make_pair(3, "Three"));

    ft::map<int, std::string>::iterator ft_it = ft_map.find(2);
    if (ft_it != ft_map.end())
        ft_map.erase(ft_it);

    for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

    std::cout << "\n\t\t\t****** STD map : *************" << std::endl;
    std::map<int, std::string> std_map;
    std_map.insert(std::make_pair(1, "One"));
    std_map.insert(std::make_pair(2, "Two"));
    std_map.insert(std::make_pair(3, "Three"));

    std::map<int, std::string>::iterator std_it = std_map.find(2);
    if (std_it != std_map.end())
        std_map.erase(std_it);

    for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
}

void map_clear()
{
    std::cout << "\n\n\t\t\t\t\t  ************** clear() ************* \t\t\t\t\t\n\n" << std::endl;

    std::cout << "\n\t\t\t****** FT map : *************\n" << std::endl;
    ft::map<int, std::string> ft_map;
    ft_map.insert(ft::make_pair(1, "One"));
    ft_map.insert(ft::make_pair(2, "Two"));
    ft_map.insert(ft::make_pair(3, "Three"));

    ft_map.clear();

    if (ft_map.empty())
        std::cout << "FT map is empty." << std::endl;

    std::cout << "\n\t\t\t****** STD map : *************" << std::endl;
    std::map<int, std::string> std_map;
    std_map.insert(std::make_pair(1, "One"));
    std_map.insert(std::make_pair(2, "Two"));
    std_map.insert(std::make_pair(3, "Three"));

    std_map.clear();

    if (std_map.empty())
        std::cout << "STD map is empty." << std::endl;
}
void map_upper()
{
    std::cout << "\n\n\t\t\t\t\t  ************** upper_bound ************* \t\t\t\t\t\n\n" << std::endl;

    std::cout << "\n\t\t\t****** FT map : *************\n" << std::endl;
    ft::map<int, std::string> ft_map;
    ft_map.insert(ft::make_pair(1, "One"));
    ft_map.insert(ft::make_pair(2, "Two"));
    ft_map.insert(ft::make_pair(3, "Three"));

    ft::map<int, std::string>::iterator it =  ft_map.upper_bound(2);
    std::cout << it->first <<  " | " << it->second << std::endl;
    ft::map<int, std::string>::iterator it1 =  ft_map.upper_bound(-5);
    std::cout << it1->first <<  " | " << it1->second << std::endl;
    std::cout << "\n\t\t\t****** STD map : *************" << std::endl;
    std::map<int, std::string> std_map;
    std_map.insert(std::make_pair(1, "One"));
    std_map.insert(std::make_pair(2, "Two"));
    std_map.insert(std::make_pair(3, "Three"));

    std::map<int, std::string>::iterator it2 =  std_map.upper_bound(2);
    std::cout << it2->first <<  " | " << it2->second << std::endl;
    std::map<int, std::string>::iterator it3 =  std_map.upper_bound(-5);
    std::cout << it3->first <<  " | " << it3->second << std::endl;
    
}
void map_lower()
{
     std::cout << "\n\n\t\t\t\t\t  ************** lower_bound ************* \t\t\t\t\t\n\n" << std::endl;

    std::cout << "\n\t\t\t****** FT map : *************\n" << std::endl;
    ft::map<int, std::string> ft_map;
    ft_map.insert(ft::make_pair(1, "One"));
    ft_map.insert(ft::make_pair(2, "Two"));
    ft_map.insert(ft::make_pair(3, "Three"));

    ft::map<int, std::string>::iterator it =  ft_map.lower_bound(2);
    std::cout << it->first <<  " | " << it->second << std::endl;
    ft::map<int, std::string>::iterator it1 =  ft_map.lower_bound(-5);
    std::cout << it1->first <<  " | " << it1->second << std::endl;
    std::cout << "\n\t\t\t****** STD map : *************" << std::endl;
    std::map<int, std::string> std_map;
    std_map.insert(std::make_pair(1, "One"));
    std_map.insert(std::make_pair(2, "Two"));
    std_map.insert(std::make_pair(3, "Three"));

    std::map<int, std::string>::iterator it2 =  std_map.lower_bound(2);
    std::cout << it2->first <<  " | " << it2->second << std::endl;
    std::map<int, std::string>::iterator it3 =  std_map.lower_bound(-5);
    std::cout << it3->first <<  " | " << it3->second << std::endl;
}
int main()
{
   // resize();
   // clear();
    //pop_back();
    //push_back();
    //insert();
    //max_size();
   //insert_fill();
    //erase_range();
    //erase();
    // map_clear();
    // map_erase();
    // map_insert();
    map_upper();
   map_lower();
    

}


 