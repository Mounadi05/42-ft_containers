#include <iostream>
#include "vector.hpp"
#include "stack.hpp"
#include <signal.h>
#include <stdatomic.h>
#include <sys/ipc.h>
#include <vector>
#include <iterator>
#include <stack>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
int _ratio = 195;

void max_size()
{
   

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
    std::cout << "*****************std****************" << std::endl;
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
void reserve()
{
    ft::vector<int> v1;
    // std::cout << v1.max_size() << std::endl;
    v1.reserve(4611686018427387908);
}

void erase()
{
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
        std::cout << "erase  : " << *(v1.erase(v1.end()-100)) << std::endl;
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
        std::cout << *(v1.end()) << std::endl;
    }
    std::cout << "****** my vector : *************"  << std::endl;
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
        std::cout << "erase  : " << *(v1.erase(v1.end()-100)) << std::endl;
        std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
        for (size_t i = 0; i < v1.size(); i++)
            std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
        std::cout << std::endl;
        std::cout << *(v1.end()) << std::endl;
    }
}
void erase_range()
{
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
    std::cout << *(v1.erase(v1.begin(), v1.begin() + 12)) << std::endl;
    std::cout << " size : " << v1.size() << "  capacity : " << v1.capacity() << std::endl;
    for (size_t i = 0; i < v1.size(); i++)
        std::cout << "value :  " << v1[i] << "  add : " << &v1[i] << " | ";
    std::cout << std::endl;
    std::cout << *(v1.end()) << std::endl;
}
void resize()
{
    ft::vector<int> v;

    for (int i = 1; i < 10; i++)
        v.push_back(i);
    std::cout << "****** my vector : " << v.capacity() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << std::endl;
    v.resize(5);
    std::cout << "****** resize 1 : " << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << std::endl;
    v.resize(8, 100);
    std::cout << "***** resize 2 : " << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << std::endl;
    v.resize(v.max_size());
    std::cout << "******* resize 3 : " << v.capacity() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << std::endl;
}

void insert()
{
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
void insert_fill()
{
    {
        // std::vector<int> v1;
        // for(int i = 1 ; i < 20; i++) v1.push_back(i);
        // for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        // v1.insert(v1.end()-10,10,12500);
        // std::cout << "\nsize : "<< v1.size() << "  capacit " << v1.capacity() <<std::endl;
        // for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        // std::cout << std::endl;
        std::vector<int> v;
       v.insert(v.begin(), 0, 64);

        v.insert(v.end(), 0, 64);

        v.insert(v.end(), 10, 64);
        v.insert(v.begin(), 5, -1);
        v.insert(v.begin() + 1, 1, -9);
        for(size_t i = 0 ; i < v.size(); i++) std::cout << v[i] <<" ";
        std::cout << std::endl; 
    }
    std::cout << "********* my ************" << std::endl;
    {
        //ft::vector<int> v1;
        // for(int i = 1 ; i < 20; i++) v1.push_back(i);
        // for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        // v1.insert(v1.end(),10,12500);
        // std::cout << "\nsize : "<< v1.size() << "  capacit " << v1.capacity() <<std::endl;
        // for(size_t i = 0; i < v1.size() ; i++) std::cout  <<  v1[i] << " ";
        // std::cout << std::endl;
        ft::vector<int> v;
        // v.insert(v.begin(), 0, 64);
        // std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;

        // v.insert(v.end(), 0, 64);
        // std::cout << "\nsize : "<< v.size() << "  capacit " << v.capacity() <<std::endl;

       
        v.insert(v.begin(), 0, 64);

        v.insert(v.end(), 0, 64);

        v.insert(v.end(), 10, 64);
        v.insert(v.begin(), 5, -1);
        v.insert(v.begin() + 1, 1, -9);

        std::cout << std::endl;
    }
}
void h()
{
    std::vector<int> v;
    ft::vector<int> ve;
    for (int i = 0; i < 5500 * _ratio; ++i) {
        ve.push_back(i);
    }
    v.push_back(ve.size());
    v.push_back(ve.capacity());
}



std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	} catch (...) { pclose(pipe); throw; }
	pclose(pipe);
	return result;
}
std::string get_leak_string(std::string s) {
	std::string tmp;
	int idx = s.find("total leaked bytes");
	for (; s[idx] != '\n' ; --idx) {}
	int edx = idx + 1;
	for (; s[edx] != '\n' ; ++edx) {}
	return s.substr(++idx, edx - 101);
}

void leaks_test(pid_t pid) {
	std::string a = "leaks ";
	a += std::to_string(static_cast<int>(pid));
	usleep(50);
	std::string s = get_leak_string(exec(a.c_str()));
    std::cout << s << std::endl;
}

void test() {
    std::vector<int> v;
    ft::vector<int> vec;
            vec.reserve(1520);
    for (int i = 0; i <10000000; ++i) {
        vec.push_back(i);
    }
    v.push_back(vec.size());
    v.push_back(vec.capacity());

}
void test1()
{    
    ft::vector<int> vector;
    std::vector<int> v;
	std::vector<int> tmp;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	vector.assign(tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(vector[i]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
 
}
void test2()
{
    ft::vector<int> vector;
    std::vector<int> v;
    for (int i = 0; i < 9900 * _ratio; ++i)
    vector.push_back(i);
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());
  
}
void walo () {
    
        test();
        test1();
       test2();
 
   
}
 
void mixed ()
{
      std::vector<int> first;
      std::vector<int> second;
      std::vector<int> third;
      std::cout << first.front() << std::endl;
      std::cout << "capacity of first: " << int (first.capacity()) << "\n**************************\n";

      first.assign (7,100);             // 7 ints with a value of 100

      std::vector<int>::iterator it;
      it=first.begin()+1;

      second.assign (it,first.end()-1); // the 5 central values of first

      int myints[] = {1776,7,4};
      third.assign (myints,myints+3);   // assigning from array.

      std::cout << "Size of first: " << int (first.size()) << '\n';
      std::cout << "Size of second: " << int (second.size()) << '\n';
      std::cout << "Size of third: " << int (third.size()) << "\n**********************\n";

      std::cout << "capacity of first: " << int (first.capacity()) << '\n';
      first.assign (15,20);             // 7 ints with a value of 100
      std::cout << "Size of first: " << int (first.size()) << '\n';

      std::cout << "capacity of first: " << int (first.capacity()) << "\n**************************\n";
      first.assign (2,70);             // 7 ints with a value of 100
      std::cout << "Size of first: " << int (first.size()) << '\n';

      std::cout << "capacity of first: " << int (first.capacity()) << "\n**************************\n";
      return 0;
    int f = 5;
    int l = 2;
    char tab [] = {10,20,30,40,50,60,70,80,90};
    ft::vector<int> a;
    a.assign(tab, tab+5);

    std::cout << "size of a: " << a.size() << "  capacity : of a" << a.capacity() << std::endl;
    for(int i = 0; i < a.size(); i++)
    std::cout << a.at(i) << " ";
    std::cout << std::endl;
    
    {
        char tab [] = {10,20,30,40,50,60,70,80,90};
        std::vector<int> a(tab, tab+6);
        std::cout << "size : " <<a.size() << " capacity : " << a.capacity() << std::endl;
        for(int i = 0; i < a.size(); i++) std::cout << a[i] << "  ";
        std::cout << std::endl << "-------------------------\n";
        a.reserve(50);
        std::cout << "size : " <<a.size() << " capacity : " << a.capacity() << std::endl;
        for(int i = 0; i < a.size(); i++) std::cout << a[i] << "  ";
        std::cout << std::endl;
    }
            std::cout << " **************** my ****************" << std::endl;

    {
        char tab [] = {10,20,30,40,50,60,70,80,90};
        ft::vector<int> a(tab, tab+6);
        std::cout << "size : " <<a.size() << " capacity : " << a.capacity() << std::endl;
        for(int i = 0; i < a.size(); i++) std::cout << a[i] << "  ";
        std::cout << std::endl << "-------------------------\n";
        a.reserve(50);
        std::cout << "size : " <<a.size() << " capacity : " << a.capacity() << std::endl;
        for(int i = 0; i < a.size(); i++) std::cout << a[i] << "  ";
        std::cout << std::endl;
    }
}

int main()
{

 
// int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
// int* check = (int*)shmat(shmid, NULL, 0);
// *check = 0;
// int f =  fork();

//     if (!f )
//     {
//         walo();
        
//         (*check)++;
//         sleep(2);
//         std::cout << "child " << std::endl;
//     }
//     if(f)
//     {
//         while(!*check);
//         std::cout << "before kill"  << std::endl;
//         leaks_test(getpid());
//         kill(f,9);
//         std::cout << "kill" << std::endl;
//     }
//     return 0;
 }


 