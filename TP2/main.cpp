#include <iostream>
#include <cstdlib>
#include <sstream>
#include <set>
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
        test_rotate_right();
        test_rotate_left();
        test_levels();
        test_gap();
        test_balance();
        test_avl();
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

    void test_rotate_left()
    {
        Node* root = new Node(10);
        root->add(5);
        root->add(15);
        root->add(12);
        root->add(20);

        Node* new_root = root->rotate_left();
        assert_false(root==new_root,"rotation left has been made")  ;
        assert_equal(15,new_root->value(),"new root is ok");
        assert_equal(5, new_root->size(),"all values are ok");
        auto values = {5,10,12,15,20};
        bool ok = true;
        for(auto value : values)
        {
            auto it = new_root->find(value);
            ok = ok & it!=TreeIterator() && it.value()==value;
        }
        assert_true(ok,"all values found");
        delete root;
    }

    void test_rotate_right()
    {
        Node* root = new Node(10);
        root->add(5);
        root->add(15);
        root->add(1);
        root->add(7);
        auto values = {1,5,7,10,15};

        Node *new_root = root->rotate_right();
        assert_false(root==new_root,"rotation right has been made")  ;
        assert_equal(5,new_root->value(),"new root is ok");
        bool ok = true;
        for(auto value : values)
        {
            auto it = new_root->find(value);
            ok = ok & it!=TreeIterator() && it.value()==value;
        }
        assert_true(ok,"all values found");
        delete root;
    }

    void test_levels()
    {
        Node* root = new Node(10);
        assert_equal(1, root->levels(),"1 level");
        root->add(5);
        assert_equal(2, root->levels(),"2 levels");
        root->add(15);
        root->add(12);
        root->add(20);
        assert_equal(3, root->levels(),"3 levels");
        delete root;
    }

    void test_gap()
    {
        Node* root = new Node(10);
        assert_equal(0, root->gap(), "root alone, gap ok");
        root->add(5);
        assert_equal(1, root->gap(), "root with left only, gap ok");
        root->add(15);
        assert_equal(0, root->gap(), "root with left & right, gap ok");
        root->add(17);
        assert_equal(-1, root->gap(), "root with more right than left, gap ok");
        delete root;
    }

    void test_balance()
    {
        Node* root = new Node(10);
        root->add(5);
        root->add(15);
        root->add(1);
        root->add(7);
        root->add(0);
        Node *new_root = root->balance();
        assert_not_equal(new_root,root,"root has changed");
        assert_equal(5, new_root->value(),"new root is ok");
        assert_equal(3, new_root->levels(),"balance is ok");
        delete new_root;
    }

    void test_avl()
    {
        Tree t;
        std::set<int> values;
        for(int i=0;i<1000;i++)
        {
            int value = std::rand();
            t.add(value);
            values.insert(value);
        }
        double theorical_depth =  1.44*log2(t.size()+2)-0.328;
        assert_true(t.depth()<=theorical_depth,"depth of balanced tree ok");

        bool ok=true;
        for(int value:values)
        {
            if(t.find(value)==t.end()) // ouch
            {
                ok=false;
                break;
            }
        }
        assert_true(ok,"values ok in balanced tree");
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
