
-----
#### 鉄則B12 
  - `printf("%.10lf", mid);` double型のprintf 

----
#### ABC 325
##### - A問題  
  - 時間系の問題   
    - 時間系で24時間超えた場合24で割ったあまりが時間になる

##### - C問題  
  - DFS
    - 再帰関数で実装


----
#### ABC 324
##### - C問題  
  - 部分列の判定
  - 貪欲法を使う


----
#### ABC 323
 - ##### A問題  
   - ビット演算  
 - ##### B問題  
   - 比較関数の書き方
    - trueならそのままfalseなら並べ替える。
      ```
        auto f = [&](int v1, int v2)->bool {
	  	if (v[v1] == v[v2])return v1 < v2;
	  	return v[v1] > v[v2];
    
	  	};
        ```
  - #####  C問題  
    - `back()` 　配列（vector）の最後の要素を取得   
    - `pop_back()` 配列（vector）の最後の要素を削除
  - #####  D問題
     - 二分探索
-------------------------------------------------------------

#### ABC 321  
##### - A問題  
 - 数値のChar型 - '0'でint型変換

##### - B問題  
 - 全探索系
 - a.back()でvectorの末尾の要素取り出せる
##### - C問題
   - bit全探索の問題
   - 部分集合  

----------------------------------------
#### ABC 317

  - ##### C問題
    - 重み付き無向グラフ
    - 全探索→再帰関数 （ラムダ式）dfs系
    - 初期化子の書き方   
    ```
    struct Edge {
	int to, cost;

	Edge(int t = 0, int c = 0) :to(t), cost(c) {};
};


#### ABC 313

  - ##### B問題
    - 考察重視の問題 
    - 入次数が0のものをみつける setを使う

    
#### ABC 306

  - ##### A問題
    - 文字列から数字はstoxxをつかう。stoi stoull
      ` std::stoull(s, 0, 2);`
      　//sは2進数の文字列　unsigened long long型に変換
  - ##### B問題
    - 考察重視の問題 
    - 入次数が0のものをみつける setを使う

#### ABC 303

  - ##### A問題
    - 小数点の計算は必ず誤差がでる。 ceil()できりあげができるが誤差が出るときがある。
    - 切り上げをしたいときの計算は以下をつかう。
    - (a+b-1)/b
    - 切り捨ては普通にわる
 
 #### ABC 297

  - ##### d問題
    - ユーグリッドの互助法 gcd（最大公約数）

#### ABC 296

  - ##### C問題
    - set同士を比較して共通の要素を取得する  
      `	set<int> se;
	set_intersection(a.begin(),a.end(),b.begin(), b.end(), inserter(se, se.begin()));
`  
#### ABC 077

  - ##### C問題
    - 二分探索

---

#### メモ  

 - まずは全探索できないか  
 - TLEの目安は10の8乗  

 - 色々な数値の表し方  
    ![](./resource/001.png)

 - 単調性があるときは二分探索ができる  
 - 1e9 = 10の9乗 2e3 = 2*10の3乗
 ----------------------------------------


  -----------------------
### visusalstudio の事   
 - Alt + Shift + 矢印キー ：　矩形選択
 - Alt + Shift + コロン   ：  単語選択

### C++のこと    
  - sort関数 （配列のソート）  
    - ```c++
      int main(){
        int a[10]{9,8,7,6,5,4,3,2,1,0};
        sort(a+1, a+4);
        // 967854321 

      }

      ```
    - 要は第一引数番目(0スタート)から第二引数番目未満を並べ替える。
   
   - map の書き方    
    - 
 
	map<int, int> m;
	m[30]++;
	m[30]++;
	m[30]++;
	m[10]++;
	m[20]++;
	m[40]++;
	for (auto& e : m) {
		cout << e.first << " : " << e.second << endl;
	}

    
    結果
    10 : 1
    20 : 1
    30 : 3
    40 : 1
    
  - x のx乗
   ```
    //xのx乗
	int x;
	cin >> x;

	ll val = 1;

	for (int i = 0; i < x; i++) {
		val *= x;
	}   
  ```
  - vectorの初期化   
  `vector<vector<int>> mp((r), vector<int>(c, -1)) ; // -1で初期化`  
    - vectorのソート
      - ` sort(vec.begin(),vec.end());`
      - ソートして重複を削除
      - ``` 
         vec.erase(unique(vec.begin(),vec.end(),vec.end());
         //unique(vec.begin(),vec.end()で隣接重複を一つまとめてうしろにゴミがたまる
         // でその後ろのところのポインタが返ってくるのでそこから後ろまで(ゴミ)を削除
            
        ```

  - 1行分読込むとき   
    ```c++
        string s;
        getline(cin,s);
    ```  
    - なぜか1行分ずれたので注意


  - 配列の最小値の添え字を取得する。
    ```
     int mn = min_element(ALL(a)) - a.begin(); 
    ```
  - 文字列
    ```
        string(s.size() - 3, '0') // 0がs.size()-3こ
        S.substr(S.size()-3); // 後ろから三文字取り出したい時
    ```
     - 置換   
     ```
     	regex re("na");
	    string fmt = "nya";
	    cout << regex_replace(s, re, fmt) << nl;

     ```

     
  - 

  - setのこと
    - 勝手に昇順になるよ
-------------------
## アルゴリズム的なこと
  - 転倒数  
    - 転倒数のMAXはたぶんnC2。n個の中から2つ選ぶ