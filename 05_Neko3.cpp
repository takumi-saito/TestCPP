# include <iostream>
using namespace std;

class Neko {
  private:
    string name;

  public:
    // コンストラクタ
    Neko(string pName);
    void naku() const;
};

/* 外部にあるクラスを呼ぶときはクラス名（Neko）を記述すること */
Neko::Neko(string pName) : name(pName){}

void Neko::naku() const {
  cout << name << ":nyanyan" << endl;
}

int main() {

  string name;
  cout << "猫の名前を決めてください" << endl;
  cin >> name;

  cout << "我輩は" << name << "である。" << endl;
  Neko octcat = Neko(name);
  octcat.naku();

}
