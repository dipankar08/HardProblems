/*******************************************************
* Problem : Write your title
* Author : Dipankar Dutta
* Date : 9/22/2016 1:38:36 PM
*******************************************************/
#include <iostream>
using namespace std;
// vector just an dynamic array, insert and delete can be at end in O(1) else takes liner time, we can do random access in O(1)
// but serach takes O(n).
// Popular operations push_back(), pop_back(), insert, erase, size, empty, clear.
#include<vector>
void test_vector() {
    vector < int > v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.insert ( v.begin() + 1,  60 ); //insert at second positions
    v.erase(v.begin() + 1); //delete second elemnet
    for ( int v1 : v) {
        cout << v1 << endl;
    }
    cout << "Empty: " << v.empty() << endl;
    cout << "size: " << v.size() << endl;
    cout << "capasity: " << v.capacity() << endl;
    cout << "Back: " << v.back() << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Direct Access:" << v[2] << " " << v.at(2) << endl;// 'std::out_of_range in case of at
    v.clear(); //delete an vector;
    cout << v.size() << endl;
}



// deque is the double endened queue on contigious array, insert/delete both ends takes O(1) but insert in middle/serach takes O(n),
// The suppoted operations are push_back(), push_front(), front,back, pop_back,pop_fornt
// You must use this when you want to queue a double ended queue.
#include<deque>
void test_deque(){
    deque < int > q = {2,  3,  4,  5};
    q.push_back(6);
    q.push_front(1);
    for(int q1 : q) {
        cout << q1 << endl;
    }
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;
    cout << "Popping" << endl;
    q.pop_back();
    q.pop_front();
    for(int q1 : q) {
        cout << q1 << endl;
    }
}




//stack is a adaptive continers build on top of vector. It supports, push, pop and top operation. this is nothing but LIFO data strucure.
#include<stack>
void test_stack() {
    stack < int > s;
    s.push(1);
    s.push(2);
    s.push(3);
    while( ! s.empty()) {
        cout << s.top() << ", ";
        s.pop();
    }
}

//queue is a adaptive continers build on top of dequeue. It supports, push , pop , front and back operation. this is nothing but FIFO data strucure.
#include<queue>
void test_queue() {
    queue < int > q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    while( ! q.empty()) {
        cout << q.front() << ", ";
        q.pop(); //pop from front
        }
}



//A priority queue is a container adaptor that provides O(1) lookup of the largest element, at the expense of O(log n) insertion cost.
// It's provides: push, pop, top and empty. while creating the priority_queue object, you can pass custom comprism function in term of functor
class Person {
    public : 
        string name;
        int age;
        Person(string i, int j):name(i),age(j){}
};

struct LessThanByAge {
    bool operator()(const Person & lhs,  const Person & rhs) const {
        return lhs.age > rhs.age;
    }
};

void test_pqueue() {
    priority_queue < Person,  std::vector < Person > ,  LessThanByAge > pq;
    pq.push(Person("Dip",10));
    pq.push(Person("Dip",15));
    pq.push(Person("Dip",14));
    while(!pq.empty()){
        cout<<pq.top().name<<" = "<<pq.top().age<<endl;
        pq.pop();
    }
}





// list is a implemenation of double linkedlist, so insertion or deletion at any point in O(1).
// but serach takes O(n) and support no random access. Inserting in any position though iterator is nothing by inserting at front of the item which is pointing to.
#include<list>
void test_list(){
    list < int > l = {2,  3,  4,  5};
    l.push_front(1);
    l.push_back(6);
    list < int > :: iterator it = l.begin();
    it++; // next elments
    cout << "Access through Iterator: " << * it << endl;
    l.insert(it,  77);//it's a insert before case..now it pointing to 2
    l.erase(it); // it will erage 2;
    //cout<<l[10]; //No random access error: no match for ‘operator[]’
    for(int l1 : l) {
        cout << l1 << endl;
    }
}




// set is a associative container build using BST, Which makes it's order set/map. They always maintin a sorted order.
// We have insert/erage (no pushback/push_front as it's nonliner) which takes O(log n ) time. insertion might fails if the elment is exist in taht case it will return false.
// find is more efficient and done by O(log n) and return s.end() if it is not found, so we must check if the serach failed or not before deref iteraot.
#include<set>
void test_set() {
    set < int > s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    //s.erase(10);
    //this is always sorted.
    for(int s1 : s) {
        cout << s1 << endl;
    }
    pair < set < int > :: iterator,  bool > ret = s.insert(3);
    cout << "return by insert:" << ret.second << endl;
    set < int > :: iterator it = s.find(1);
    if(it == s.end()) {
        cout << "search failed." << endl;
    } else {
        cout << "Found: " << * it << endl;
    }
}



// Map is implemeted as BST as they need to be a ordered map. they support insert, find, erage in O(log n), multimap is supposrts having multiple same key.
// the key can't be modified in case of map/multimap.
#include<map>
void test_map() {
    map < int,  string > m;
    m.insert( pair < int,  string > (2,  "dip"));
    m.insert( make_pair(1,  "sup") );
    for(pair < int,  string > m1 : m) {
        cout << m1.first << " : " << m1.second << endl;
    }
    //something like has_key, get
    if(m.find(1) != m.end()) {
        map < int,  string > :: iterator ret = m.find(1);
        cout << "Found :" << ( * ret).first << " => " << ( * ret).second << endl;
    }
}



// Introduced in C++11, This is simlar as ordered map, but they are implemneted using hash map, thus the printing order can't be sorted and shows in a arbitary order.
// insert, delete, find is fast and in O(1), STL also support some api to provide hash table info like load_factor, bucket_count, bucket.
#include<unordered_map>
void unorder_map() {
    unordered_map < int, string > om;
    om.insert(make_pair(10, "Dipankar"));
    om.insert(make_pair(9, "Dipankar"));
    om.insert(make_pair(11, "Dipankar"));
    // the output is ounordered
    for(pair < int,  string > om1 : om) {
        cout << om1.first << " : " << om1.second << endl;
    }
    cout << "Load Factor = " << om.load_factor() << endl;
    cout << "Total Bucket size = " << om.bucket_count() << endl;
    cout << "which bucket = " << om.bucket(10) << endl;
}



int main() {
    //test_vector();
    //test_deque();
    //test_stack();
    //test_queue();
    test_pqueue();
    //test_list();
    //test_set();
    //test_map();
    //unorder_map();
    return 0;
}

