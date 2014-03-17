#include <iostream>
#include <vector>

using namespace std;

struct node{

    int name;
    int prevordist;
    int dist_sol;

};

vector< vector<node> > vov;
int counter = 0;

int search_vov( int num ){

    int pos, i = 0;
    for( i = 0; i < vov.size(); i++ ){
        if( vov[i][0].name == num ){
            return i;
        }
    }
    if( i == vov.size() )
        return -1;

}

void make_list( int a, int b, int dist ){

    int pos;
    pos = search_vov( a );
    node *n = new node;

    if( pos == -1 ){

        n -> name = a;
        n -> prevordist = -1;
        n -> dist_sol = -1;

        vector<node> temp;

        temp.push_back( *n );

        node *c = new node;
        c -> name = b;
        c -> prevordist = dist;
        c -> dist_sol = -1;

        temp.push_back( *c );

        vov.push_back( temp );
    }else{
        n -> name = b;
        n -> prevordist = dist;
        n -> dist_sol = -1;
        vov[pos].push_back( *n );
    }

}

void print_list( ){

    for( int i = 0; i < vov.size(); i++ ){
        for( int j = 0; j < vov[i].size(); j++ ){
            cout <<"name : "<< vov[i][j].name << "prevordist : " << vov[i][j].prevordist <<"dist_sol : " << vov[i][j].dist_sol << endl;
        }
        cout << endl;
    }

}

void find_count( int num ){

    int pos, i;
    pos = search_vov( num );
    if( pos == -1 )
        cout << "capital not found\n";
    else{
        for( i = 1; i < vov[pos].size(); i++ ){

        }
    }

}

int main( ){

    int n, m, s, l, i = 0, a, b, c;
    cin >> n >> m >> s;

    for( i = 0; i < m; i++ ){
        cin >> a >> b >> c;
        make_list( a, b, c );
        make_list( b, a, c );
    }
    cin >> l;
//    cout << "printing list\n";
//    print_list();
    find_count( s );

    return 0;

}
