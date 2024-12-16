#include <iostream>
#include <cstdlib>
#include <sstream>
#include "tree.h"
#include "test.h"
using namespace std;

class TestTree : public tests::Test
{
    protected:
    void test_code() override
    {
        test_size();
        test_add();
        test_find();        
        test_begin();
        test_next();
        test_iterate();
    }
    private:
    void test_size()
    {
        Tree test;
        assert_equal(0,test.size(),"test empty tree");
    }
    void test_add()
    {
        Tree t ;
        t.add(10) ;
        t.add(15) ;
        t.add(10) ;
        t.add(5) ;
        assert_equal(3,t.size(),"test some adds");
    }
    void test_find()
    {
        Tree t ;
        t.add(10) ;
        t.add(15) ;
        t.add(9) ;
        t.add(5) ;

        auto it = t.find(9);
        assert_true(it!=t.end() && it.value()==9,"test of found");            

        it = t.find(34);
        assert_true(it==t.end(),"Test not found");
    }
    void test_iterate()
    {
        std::ostringstream strBuilder;
        Tree t;
        t.add(10);
        t.add(-4);
        t.add(8);
        t.add(12);
        t.add(8);
        t.add(46);
        t.add(0);
        t.add(92);
        for(auto i = t.begin();i!=t.end();++i)
        {
            strBuilder << *i << ' ';
        }
        std::string str = strBuilder.str();
        assert_equal(std::string("-4 0 8 10 12 46 92 "),str,"iterate test");
    }
    void test_begin()
    {
        Tree t;
        t.add(10);
        t.add(-4);
        t.add(8);
        t.add(12);
        t.add(8);
        t.add(46);
        t.add(0);
        t.add(92);
        TreeIterator begin = t.begin();        
        assert_equal(-4, begin.value(),"begin of tree is lowest");
    }
    void test_next()
    {
        Tree t;
        t.add(10);
        t.add(-4);
        t.add(8);
        t.add(12);
        TreeIterator it = t.begin(); // -4
        it.next(); // 8 
        it.next(); // 10
        assert_equal(10,it.value(),"next of 8 is 10");
        it.next(); // 12
        it.next(); // out of range
        assert_true(it==t.end(),"end of tree");

        assert_throws<InvalidIterator>( [](){
            Tree t;
            TreeIterator it = t.begin();
            it.next();    
        },"next on invalid iterator throws exception");
    }
};

int main()
{
    cout << "Test of binary tree !" << endl;
    
    TestTree tests;
    tests.run();

    cout << "Final : visual Test of tree" << endl;
    Tree t;
    for(int i=0;i<100;i++)
    {
        t.add(rand()); // add random integers values between 0 and 32767 (RAND_MAX)
    }
    cout <<"There is "<<t.size()<<" values."<<endl;
    cout << "The whole tree is : ";
    for(auto i=t.begin();i!=t.end();++i)
    {
        cout << *i << ' ';
    }
    cout << endl;


    return 0;
}
