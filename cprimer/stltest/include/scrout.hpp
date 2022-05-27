/******************************************************
**
*******************************************************/
#pragma once
#include <iostream>
#include <tuple>
#include <iostream>
#include <set>
#include <bitset>
#include <tuple>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <sstream>
#include <string>
#include <initializer_list>


class ScrOut;
ScrOut& tab(ScrOut& dc);
ScrOut& cut(ScrOut& dc);
ScrOut& cl(ScrOut& dc);
ScrOut& el(ScrOut& dc);
ScrOut& endl(ScrOut& dc);

//布尔测试宏
#ifndef isok
#define isok(a) ((a)==true)
#endif

#define vec(T) vector<T>
#define nonull(v) (((v )!=nullptr )&&(&(v )!=nullptr ) )
#define addmenu(name) addmenuitem(#name,name);

#define gett(name)  decltype(name)
#define getit(name)  gett(name.begin())
#define getI(name)  gett(name)::iterator
#define getCI(name)  gett(name)::const_iterator
#define ALL(V)  V.begin(),V.end()
#define NTIME(N)  for(size_t ix=0;ix<(N);++ix)
#define FOREVER  for(;;)
#define FORALL(V,iterator)  for(getCI(V) iterator = V.begin(); iterator != V.end();++iterator)
#define FORALLW(V,iterator)  for(getCI(V) V##iterator = V.begin(); V##iterator != V.end();++V##iterator)
#define FORN(N,icountn)  for(size_t icountn=0;icountn<(N);++icountn)
#define FORV(ielement,V)  for(const auto &ielement:V)
#define FORW(ielement,V)  for(auto &ielement:V)

#define makedc(cout)  unique_ptr<ScrOut> me_unique_dc=make_unique<ScrOut>(); ScrOut & cout=*me_unique_dc;
#define makemedc(DC)  unique_ptr<ScrOut> pdc(new ScrOut());ScrOut& DC = *pdc;
#define SimulationStdCout  auto cout_me_ptr=make_unique<ScrOut>();auto& cout= *cout_me_ptr;

//测试字符串是否为空的宏
#ifndef isempty
#define isempty(astr) ((astr) == (""))
#endif // !empty

#ifndef st
#define st(...) (#__VA_ARGS__)
#endif
#define sst(code,...)  #code##","#__VA_ARGS__
#define lcode(...)	cout<<"source code is:"<<el<<"{ "#__VA_ARGS__<<" }"<<el<<"run result is: "<<el<<cut;__VA_ARGS__;
#define lscode(...)  lcode(__VA_ARGS__)
#define showcode(...)	lcode(__VA_ARGS__)
#define showcodes(...)	lscode(__VA_ARGS__)

#define SHOW(name) cout<<st(name)<<" is: "<<name<<tab
#define showv(name) st(name)<<" value is: "<<name<<tab
#define showtype(...)  cout<<#__VA_ARGS__<<" type:  "<<typeid(##__VA_ARGS__).name()<<"  size:  "<<sizeof(##__VA_ARGS__)<<"  HASH: "<<typeid(##__VA_ARGS__).hash_code()<<el;

#define RUNTEST(message)		/*cout.clearscreen();\
								cout.titleline(wstring(st(message)));*/

#define TITLE(message)      cout.title(string(st(message)));
#define BEGINTEST(times)  {size_t itimes=times;\
					auto start = clock( );\
					NTIME( itimes){

#define ENDTEST 	};auto end = clock( );\
					cout << cut;\
					cout <<itimes<<"-times run Totaltimes: ";\
					cout<<(long double)( ( (long double)end - (long double)start ) * 1000 / CLOCKS_PER_SEC ) << "\'ms";\
					cout<<"  One time: ";\
					cout<<(long double)( ( (long double)end - (long double)start ) * 1000*1000) / (CLOCKS_PER_SEC *itimes);\
					cout<<"\'us  Total clock is: "<<end-start<<"  ";\
					cout<<st(CLOCKS_PER_SEC :)<<CLOCKS_PER_SEC<<'.'<<endl;}


////
class ScrOut:public std::ostream
{
public:
    using iodc=decltype(::cout);
    using dc=ScrOut;
    iodc &cout=::cout;
    dc& me=*this;
    bool ibegin=true;
    size_t  ilinemod=10;
    unsigned int id=0;
    static unsigned int dcsum;
    size_t linelen=80;
    char linechar='-';
    string starline;


public:
    ScrOut(unsigned int dcid=0):cout(::cout),id(dcid),starline(linelen,linechar)
    {
        ++dcsum;
        *this<<id<<"#" <<"decive is ready .("<<dcsum<<')'<<el<<cut<<el;
    };
    ~ScrOut()
    {
        --dcsum;
        *this<<id<<"#" <<"decive is destroy .("<<dcsum<<')'<<el<<cut<<el;
    };

public:
    ScrOut& operator << (ScrOut& (*op) (ScrOut&));

public:


public:
    ScrOut& cutline(char c='*')
    {
        *this << starline;
        linechar=c;
        return *this;
    };
    void linemod(size_t l,size_t line, ScrOut& (*op)(ScrOut&)=nullptr, char* stail=nullptr);
    template<typename T> ScrOut& forprintr(const T* b, const T* e);
    template<typename T> ScrOut& forprintv(const T& v);
    template<typename T> ScrOut& forprintm(const T& m);
    template<typename T, size_t N = std::tuple_size<T>::value> dc& disptup(T t);


public:
    template<typename T> dc& operator <<(const T& a)
    {
        ::cout<<a;
        return *this;
    };
//    template <typename iossetX>
//    using iossetX=decltype(boolalpha);
//    template <typename iossetX>
//    iodc&  operator <<(const iossetX& a)
//    {
//        ::cout<<a;
//        return ::cout;
//    };
    template <typename X> ScrOut& operator <<(const unique_ptr<X>& unptr);
    template <typename T, size_t len> ScrOut& operator <<(const array<T, len>& a);
    template <typename T > ScrOut& operator ()(initializer_list<T> c);
    template <typename T > ScrOut& operator<<(initializer_list<T> c);
    template <typename T> ScrOut& operator <<(const list<T>& l);
    template <typename X> ScrOut& operator <<(const vector<X>& v);
    template <typename T> ScrOut& operator <<(const deque<T>& d);
    template <typename T, typename X> ScrOut& operator <<(const map<T, X>& m);
    template <typename T, typename X> ScrOut& operator <<(const multimap<T, X>& m);
    template <typename T> ScrOut& operator <<(const set<T>& s);
    template <typename T> ScrOut& operator <<(const multiset<T>& s);
    template <typename ...T> dc& operator <<(tuple<T...> t);


public:
    ScrOut& pl()
    {
        return *this;
    }
    template <typename T, typename ...X> ScrOut& pl(T a, X...args);
    template <typename X> ScrOut& pt(X a);
    template <typename T, typename ...X> ScrOut& pt(T a, X...args);
    template <typename X> ScrOut& pc(X a);
    template <typename T, typename ...X> ScrOut& pc(T a, X...args);
    template <typename X> ScrOut& pb(X a);
    template <typename T, typename ...X> ScrOut& pb(T a, X...args);
    template <typename X> ScrOut& address(X& a);
    template <typename X> ScrOut& address(X&& a);
    template <typename T, typename ...X> ScrOut& address(T a, X...args);
    ScrOut& type()
    {
        return *this;
    };
    template <typename T, typename ...X> ScrOut& type(const T& a, const X&...args) ;
    template <typename T, typename ...X> ScrOut& type(const T&& a, const X&&...args) ;
    template <typename A, typename B> ScrOut& operator <<(const pair<A, B>& i);
    ScrOut& setimod(int imod);
    const char setlinechar(const char& c = '=');
};

unsigned int ScrOut::dcsum=0;

ScrOut& ScrOut::setimod(int imod)
{
    this->ilinemod = imod;
    return *this;
}

const char ScrOut::setlinechar(const char& c)
{
    char rc = this->linechar;
    this->linechar = c;
    return rc;
}

template <typename A, typename B>
ScrOut& ScrOut::operator <<(const pair<A, B>& i)
{
    *this << "{" << i.first << "," << i.second << "}   ";
    return *this;
}

template <typename T, typename ...X>
ScrOut& ScrOut::type(const T& a,const  X&...args)
{
    *this << "type:  " << typeid(a).name() << "  size:  " << sizeof(a) << "  HASH: " << typeid(a).hash_code() << el;
    return type(args...);
}

template <typename T, typename ...X>
ScrOut& ScrOut::type(const T&& a,const  X&&...args)
{
    *this << "TYPE:  " << typeid(a).name() << '\t' << "SIZE:  " << sizeof(a) << '\t' << "HASHCODE: " << typeid(a).hash_code() << el;
    return type(args...);
}

template <typename T, typename ...X>
ScrOut& ScrOut::pl(T a, X...args)
{
    *this << a << '\n';
    pl(args...);
    return *this;
}

template <typename X>
ScrOut& ScrOut::pt(X a)
{
    *this << a << '\n';
    return *this;
}

template <typename T, typename ...X>
ScrOut& ScrOut::pt(T a, X...args)
{
    *this << a << '\t';
    pt(args...);
}

template <typename X>
ScrOut& ScrOut::pc(X a)
{
    *this << a << '\n';
    return *this;
}

template <typename T, typename ...X>
ScrOut& ScrOut::pc(T a, X...args)
{
    *this << a << ", ";
    pc(args...);
    return *this;
}

template <typename X>
ScrOut& ScrOut::pb(X a)
{
    *this << '{' << a << "}" << '\n';
    return *this;
}

template <typename T, typename ...X>
ScrOut& ScrOut::pb(T a, X...args)
{
    *this << '{' << a << "},";
    return pb(args...);
}

template <typename X>
ScrOut& ScrOut::address(X&& a)
{
    *this << address(a)<<'\t';
    return *this;
}

template <typename X>
ScrOut& ScrOut::address(X& a)
{
    *this << address(a)<<'\t';
    return *this;
}

template <typename T, typename ...X>
ScrOut& ScrOut::address(T a, X...args)
{
    *this << address(a)<<'\t';
    return address(args...);
}

void ScrOut::linemod(size_t l,size_t line, ScrOut& (*op)(ScrOut&), char* stail)
{
    if (++l % line == 0)
        {
            (*op)(*this);
            if (stail)
                *this << stail;
        }
}

ScrOut& ScrOut::operator << (ScrOut& (*op) (ScrOut&))
{
    return (*op) (*this);
}


template<typename ...T>
ScrOut& ScrOut::operator <<(tuple<T...> t)
{
    disptup(t);
    return me;
}

template<typename T, size_t N>
ScrOut& ScrOut::disptup(T t)
{
    constexpr size_t M = std::tuple_size<T>::value;
    constexpr size_t I = M - N;
    if(ibegin)
        me<<"{ ";
    ibegin=false;
    if constexpr (N == 1)
        {
            *this << "{" << std::get<I>(t) << "} }";
            ibegin=true;
        }
    else
        {
            *this << "{" << std::get<I>(t) << "},";
            disptup<T, N - 1>(t);
        }
    return me;
};

template<typename T>
ScrOut& ScrOut::forprintr(const T* b, const T* e)
{
    int il = 0;
    for (auto* it = b; it != e; ++it)
        {
            *this << *it << tab;
            linemod(il, ilinemod);
        }
    return *this;
}

template<typename T>
ScrOut& ScrOut::forprintv(const T& v)
{
    int il = 0;
    for (auto i : v)
        {
            *this << i << tab;
            linemod(il, ilinemod);
        }
    return *this;
}

template<typename T>
ScrOut& ScrOut::forprintm(const T& m)
{
    int il = 0;
    for (const auto& i : m)
        {
            *this << "{" << i.first << "," << i.second << "}   ";
            linemod(il, ilinemod);
        }
    return *this;
}

template <typename T, size_t len>
ScrOut& ScrOut::operator <<(const array<T, len>& a)
{
    if (len == 0 || &a == nullptr)
        return *this;
    else
        return forprintv(a);
}

template <typename X>
ScrOut& ScrOut::operator <<(const vector<X>& v)
{
    if (v.empty())
        return *this;
    else
        return forprintv(v);
}

template <typename T>
ScrOut& ScrOut::operator <<(const deque<T>& d)
{
    if (d.empty())
        return *this;
    else
        return forprintv(d);
}

template <typename T, typename X>
ScrOut& ScrOut::operator <<(const map<T, X>& m)
{
    if (!m.size())
        return *this;
    else
        return forprintm(m);
}

template <typename T, typename X>
ScrOut& ScrOut::operator <<(const multimap<T, X>& m)
{
    if (!m.size())
        return *this;
    else
        return forprintm(m);
}

template <typename T>
ScrOut& ScrOut::operator <<(const multiset<T>& s)
{
    if (!s.size())
        return *this;
    else
        return forprintv(s);
}

template <typename T>
ScrOut& ScrOut::operator <<(const set<T>& s)
{
    if (!s.size())
        return *this;
    else
        return forprintv(s);
}

template <typename T>
ScrOut& ScrOut::operator <<(const list<T>& l)
{
    if (!l.size())
        return *this;
    else
        return forprintv(l);
}

template<typename T >
ScrOut& ScrOut::operator ()(initializer_list<T> c)
{
    T ibegin = *c.begin() - *c.begin();
    forprintv(c);
    return *this;
}

template<typename T >
ScrOut& ScrOut::operator<<(initializer_list<T> c)
{
    T ibegin = *c.begin() - *c.begin();
    forprintv(c);
    return *this;
}


template <typename X>
ScrOut& ScrOut::operator <<(const unique_ptr<X>& unptr)
{
    *this<<(void*) unptr.get();
    return *this;
}

ScrOut& tab(ScrOut& dc)
{
    dc << '\t';
    return dc;
}

ScrOut& cut(ScrOut& dc)
{
    dc.cutline();
    return dc<<'\n';

}

ScrOut& cl(ScrOut& dc)
{
    system("clear");
    return dc;
}

ScrOut& endl(ScrOut& dc)
{
    dc <<'\n';
    return dc;
}

ScrOut& el(ScrOut& dc)
{
    dc <<'\n';
    return dc;
}


template <typename T>
auto address(T& x)
{
    return &x;
}

template <typename T>
bool swap(T& a, T& b)
{
    if ((a != nullptr) && (b != nullptr) && (&a != nullptr) && (&b != nullptr) && (&a != &b))
        {
            T c;
            c = a;
            a = b;
            b = c;
            return true;
        }
    return false;
}

template<typename V, typename T>
T emax(V v)
{
    T imax = *v.begin();
    if (v.size())
        {
            for (const auto& i : v)
                {
                    imax = max(imax, i);
                }
        }
    return imax;
}

template<typename T = long double, typename ...X>
T gmax(T a, X...args)
{
    initializer_list<T>il{ (T)a,(T)(args)... };
    return emax<initializer_list<T>, T>(il);
}

template<typename T = int, typename ...X>
T imax(X...args)
{
    initializer_list<T>il{ (T)(args)... };
    return emax<initializer_list<T>, T>(il);
}

template<typename T = int>
T lex(T a = T())
{
    return a;
}

template<typename T >
auto sum(vector<T> c)
{
    T isum = *c.begin() - *c.begin();
    for (auto i : c)
        isum += i;
    return isum;
}

template<typename T >
auto sum(initializer_list<T> c)
{
    T isum = *c.begin() - *c.begin();
    for (auto i : c)
        isum += i;
    return isum;
}


