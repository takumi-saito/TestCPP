# include <iostream>
using namespace std;

class Neko {
  private:
    string name;

  public:
    // コンストラクタ
    Neko(string pName) : name(pName){}
    void naku() const {
      cout << name << ":nyanyan" << endl;
    }
};

int main() {
  Neko octcat = Neko("octcat");
  Neko dora = Neko("dora");
  Neko tama = Neko("tama");
  octcat.naku();
  dora.naku();
  tama.naku();
}
