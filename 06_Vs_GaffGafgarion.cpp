# include <iostream>

// キャラクラス
class Character {
  // status
private:
  int hp;
  int power;


  // setter,getter
public:
  void setHp(int php) {
    hp = php;
  }
  void setPower(int ppower) {
    power = ppower;
  }
  int getHp() {
    return hp;
  }
  int getPower() {
    return power;
  }
  // コンストラクタ
  Character() {
      hp = 250;
      power = 25;
  }
  Character(int php, int ppower) {
      hp = php;
      power = ppower;
  }

};


// スキルクラス
class Skill {
  Character me;
  Character enemy;

public:
  Character getMe() {
    return me;
  }
  Character getEnemy() {
    return enemy;
  }
  Skill(Character pme, Character penemy) {
    me = pme;
    enemy = penemy;
  }
  // 闇の剣
  void shadowSword() {
    std::cout << "剣士ガフガリオン\n「神に背きし剣の極意 その目で見るがいい…闇の剣！」" << std::endl;
    // 回復
    enemy.setHp(enemy.getHp() + enemy.getPower());
    // ダメージ
    me.setHp(me.getHp() - enemy.getPower());
  }
  // 雄叫び
  void warCry() {
    me.setPower(me.getPower() * 2);
  }
  void attack() {
    // 攻撃
    enemy.setHp(enemy.getHp() - me.getPower());
  }
};
// 行動

/* メイン */
int main() {
  int safeCnt = 10;
  Character ramza = Character(200, 20);
  Character gaff = Character();
  Skill skill = Skill(ramza, gaff);

  std::string hoge;

  while (safeCnt > 1) {
      std::cout << "残りターン：" << safeCnt << std::endl;
      std::cout << "剣士ラムザのターンです。" << std::endl;

      int skillFlg;
      std::cout << "１：攻撃、２：スキル" << std::endl;
      std::cin >> skillFlg;
      switch (skillFlg) {
        case 1:
          std::cout << "剣士ラムザの攻撃！" << std::endl;
          skill.attack();
          std::cout << "ラムザ残りHP：" << skill.getMe().getHp() << std::endl;
          std::cout << "ガフガリオン残りHP：" << skill.getEnemy().getHp() << std::endl << std::endl;
          break;
        case 2:
          std::cout << "剣士ラムザのスキル\n「雄叫び」" << std::endl;
          skill.warCry();
          break;
        default:
          exit(0);
          break;
      }

      // どちらかのHPがなくなるまでターンをループ
      if (skill.getMe().getHp() < 1) {
        std::cout << "GAME OVER" << std::endl;
        break;
      }
      if (skill.getEnemy().getHp() < 1) {
        std::cout << "剣士ガフガリオン\n「むぅ……、こ、このオレが敗れるのか……？」" << std::endl;
        break;
      }

      std::cin >> hoge;

      std::cout << "ガフガリオンのターン" << std::endl;
      // 闇の剣
      skill.shadowSword();
      std::cout << "ラムザ残りHP：" << skill.getMe().getHp() << std::endl;
      std::cout << "ガフガリオン残りHP：" << skill.getEnemy().getHp() << std::endl << std::endl;

      std::cin >> hoge;


      // どちらかのHPがなくなるまでターンをループ
      if (skill.getMe().getHp() < 1) {
        std::cout << "GAME OVER" << std::endl;
        break;
      }
      if (skill.getEnemy().getHp() < 1) {
        std::cout << "剣士ガフガリオン\n「むぅ……、こ、このオレが敗れるのか……？」" << std::endl;
        break;
      }
      std::cout << std::endl;
      safeCnt--;
  }
  std::cout << "end" << std::endl;
}
