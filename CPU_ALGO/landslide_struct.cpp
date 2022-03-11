#include<iostream>
#include<vector>
#include<algorithm>
#define SIZE 1000
using namespace std;

int n, m;
bool check_overflow(int id, int size, int cntlevel);
struct st {
    int id;
    int size;
};

vector<struct st> v[SIZE];
int Heap_MAX[SIZE];
int Heap_MAXNOW[SIZE];


bool is_only(int id, int size, int cntlevel) {
    int loop_count = v[cntlevel].size();
    for (int i = 0; i < loop_count; i++) {
        if (v[cntlevel][i].id == id) {  //값이 중복된다면
            Heap_MAXNOW[cntlevel] -= v[cntlevel][i].size;
            v[cntlevel].erase(v[cntlevel].begin() + i); //중복된 값을 제거하고
            
            return false;
        }
    }
    return true;
}

void landslide(int cntlevel) {
    int level = cntlevel;
    int loop_size = v[cntlevel].size();
    for (int i = 0; i < loop_size; i++) {
        if (v[cntlevel + 1].size() > 0) {
            is_only(v[cntlevel][i].id, v[cntlevel][i].size, cntlevel+1); //값이 중복된다면 제거하고 새로운 데이터 삽입
        }
            v[level + 1].push_back(v[cntlevel][i]);
            Heap_MAXNOW[cntlevel + 1] += v[cntlevel][i].size;
       
    }

    if (check_overflow(0, 0, cntlevel + 1))
    {
        landslide(cntlevel + 1);
    }
    v[level].erase(v[level].begin(), v[level].end());
    Heap_MAXNOW[level] = 0;

}

bool check_overflow(int id, int size, int cntlevel) {
    int max = Heap_MAX[cntlevel];
    int loop_count = v[cntlevel].size();
    int sum = 0;
    for (int i = 0; i < loop_count; i++) {
        sum += v[cntlevel][i].size;
        if (sum > Heap_MAX[cntlevel]) {
            return true;
        }
    }

    return false;
}



int main() {
    cin >> n >> m;
    fill_n(Heap_MAX,SIZE,10000000);
    //heap 크기 입력
    for (int i = 0; i < n-1; i++)
    {
        int tmp;
        cin >> tmp;
        Heap_MAX[i] = tmp;
    }
    struct st tmp;
    //자료구조 입력 시작
    for (int i = 0; i < m; i++) {
        int id, size;
        cin >> id >> size;
        tmp.id = id;
        tmp.size = size;
        int cntlevel = 0;
        //중복 되는거 먼저 처리
       
        if (!is_only(id, size, cntlevel)) { // 만약 값이 중복되었다면 중복된 값을 지움
            v[cntlevel].push_back(tmp); //최신값 삽입
            Heap_MAXNOW[cntlevel] += tmp.size;
            if (check_overflow(id, size, cntlevel)) { //값이 넘어간다면
              //산사태 발생
                landslide(cntlevel++);
            }
            else { //넘어가지 않는다면 다음입력 받기
                continue;
            }

        }
        else { //중복되지 않았다면
            v[cntlevel].push_back(tmp); //최신값 삽입
            Heap_MAXNOW[cntlevel] += tmp.size;
            if (check_overflow(id, size, cntlevel)) {
                //넘어갔다면 산사태발생
                landslide(cntlevel++);
                
            }
            else {//넘어가지 않는다면 다음입력 받기
                continue;
            }

        }

    }





    cout << "출력시작" << '\n';
    
    //출력부분
    for (int i = 0; i <= n; i++) {
        int loop_count = v[i].size();
        if (loop_count == 0) {
            cout << '\n';
            continue;
        }
        
        for (int j = 0; j < loop_count; j++) {
            cout << v[i][j].id << ',';
            cout << v[i][j].size;
            cout << " ";
        }
        cout << '\n';
    }




    return 0;
}
