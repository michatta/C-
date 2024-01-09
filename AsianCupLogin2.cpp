#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

//회원가입과 로그인 클래스
class CreateAccount //회원 가입 클래스
{
public:
  // CreateAccount() { information = {}; }
  void clear();
  void FirstPage();
  void SignUpPage();
  void CreateAccountPage();
  void ReservationPage();
  void PrintLogo();
  void IdInput(string id);
  int IdDu(string id); 
  string IdFind(string phonenumber);
  void PwInput(string pw);
  int PwDu(string id, string pw);
  string PwFind(string phonenumber);
  int PwSet(string pw);
  void EmailInput(string email);
  int EmailDu(string email);
  void PhoneNumberInput(string phonenumber);
  int PhoneNumberDu(string phonenumber);
  void FileSave();
  int MemBerNumber();
    vector<int> MemberNumber;
  //void ShowResult();

private:
  vector<string> information;
  vector<string> Id;
  vector<string> Pw;
  vector<string> Email;
  vector<string> PhoneNumber;

};
void CreateAccount::clear() { information.clear(); }
void CreateAccount::PrintLogo() {
  string line;
  ifstream file("AsianCupLogo");
  if (file.is_open()) {
    while (getline(file, line))
      cout << line << endl;
    file.close();
  } else {
    cout << "Unable to open file";
  }
}
void CreateAccount::FirstPage() {
  //system("clear");
  PrintLogo();
  cout << "------------------------" << endl;
  cout << "1. 아시안컵 정보 알아보기" << endl;
  cout << "2. 경기 예매하기" << endl;
  cout << "------------------------" << endl;
}
void CreateAccount::SignUpPage() {
  //system("clear");
  PrintLogo();
  cout << "------------------------" << endl;
  cout << "1. 로그인하기" << endl;
  cout << "2. ID 찾기" << endl;
  cout << "3. PW 찾기" << endl;
  cout << "4. 회원가입하기" << endl;
  cout << "------------------------" << endl;
}
void CreateAccount::CreateAccountPage() {
  system("clear");
  PrintLogo();
  cout << "------------------------" << endl;
  cout << "회원가입 정보 입력하기" << endl;
  cout << "------------------------" << endl;
}
void CreateAccount::ReservationPage() {
  system("clear");
  PrintLogo();
  cout << "------------------------" << endl;
  cout << "경기 예매를 위해 먼저 날짜를 선택해주세요." << endl;
  cout << "------------------------" << endl;
}
void CreateAccount::IdInput(string id) { information.push_back(id); } //ID를 벡터에 넣음.
int CreateAccount::IdDu(string id) { //ID 중복검사
  if (Id.size() != 0) {
    for (int i = 0; i < Id.size(); i++)
      if (Id[i] == id)
        return 0;
  }
  return 1;
}
string CreateAccount::IdFind(string phonenumber) { //전화번호를 이용해 ID를 찾는 함수
  string s = "그런 ID는 읎다.";
  if (PhoneNumber.size() != 0) {
    for (int i = 0; i < PhoneNumber.size(); i++)
      if (PhoneNumber[i] == phonenumber)
        return Id[i];
  }
  return s;
}
void CreateAccount::PwInput(string pw) { information.push_back(pw); } //비밀번호를 저장
int CreateAccount::PwDu(string id,string pw) { //Id와 일치하는 비번 찾기
  if (Id.size() != 0) {
    for (int i = 0; i < Id.size(); i++)
      if (Pw[i] == pw)
        return 1;
  }
  else
    return 0;
}
string CreateAccount::PwFind(string phonenumber) { //전화번호를 이용해 ID를 찾는 함수
  string s = "그런 비밀번호는 읎다.";
  if (PhoneNumber.size() != 0) {
    for (int i = 0; i < PhoneNumber.size(); i++)
      if (PhoneNumber[i] == phonenumber)
        return Pw[i];
  }
  return s;
}
int CreateAccount::PwSet(string pw) //비밀번호를 처음 설정할 때 기준에 맞추어 해야한다(5글자 이상).
{
    if(pw.size() < 5)
        return 0;
    return 1;
}
void CreateAccount::EmailInput(string email) { information.push_back(email); } //이메일을 벡터에 저장
int CreateAccount::EmailDu(string email) //이메일 중복 검사.
{ 
    if (Email.size() != 0) {
    for (int i = 0; i < Email.size(); i++)
      if (Email[i] == email)
        return 0;
  }
  return 1;
}
void CreateAccount::PhoneNumberInput(string phonenumber) { information.push_back(phonenumber);}
int CreateAccount::PhoneNumberDu(string phonenumber)
{ 
    if (PhoneNumber.size() != 0) {
    for (int i = 0; i < PhoneNumber.size(); i++)
      if (PhoneNumber[i] == phonenumber)
        return 0;
  }
  return 1;
}
int CreateAccount::MemBerNumber() {
  int Mnumber = rand() % 100;
  cout << "고유한 회원 번호를 부여합니다." << endl;
  MemberNumber.push_back(Mnumber); //형 변환해서 회원정보 vector 마지막 부분에 넣기
  return Mnumber;
}
// void CreateAccount::ShowResult() {
//   Id.push_back(information[0]);
//   Pw.push_back(information[1]);
//   Email.push_back(information[2]);
//   PhoneNumber.push_back(information[3]);
// }
void CreateAccount::FileSave() {
  string line;
  ofstream file("ex.csv", std::ios::app);
  if (file.is_open()) {
    for (int i = 0; i < information.size(); i++)
      file << information[i] << ",";
    file << endl;
    Id.push_back(information[0]);
    Pw.push_back(information[1]);
    Email.push_back(information[2]);
    PhoneNumber.push_back(information[3]);
    file.close();
  }
}







//스포츠 정보를 알려주는 class
class SportsInformation
{
public:
    void KoreaList(); // 한국 선수팀 명단
    void GroupList(); // 조별 리스트
    void GroupPlay(); //조별 경기
    void Overall(); // 경기 일정 & 개최지
    void Sportspage();
    
};
void SportsInformation::Sportspage()
{
  cout << "------------------------" << endl;
  cout << "1. 경기 일정 & 개최지" << endl;
  cout << "2. 참가국 및 조별 리스트" << endl;
  cout << "3. 조별 경기 일정" << endl;
  cout << "4. 한국 선수팀 명단" << endl;
  cout << "------------------------" << endl;
}
void SportsInformation::Overall()
{
  string line;
  ifstream file("Overall");
  if (file.is_open()) {
    while (getline(file, line))
      cout << line << endl;
    file.close();
  } else {
    cout << "Unable to open file";
  }
}
void SportsInformation::KoreaList()
{
  string line;
  ifstream file("KoreaList");
  if (file.is_open()) {
    while (getline(file, line))
      cout << line << endl;
    file.close();
  } else {
    cout << "Unable to open file";
  }
}
void SportsInformation::GroupList()
{
  string line;
  ifstream file("GroupList");
  if (file.is_open()) {
    while (getline(file, line))
      cout << line << endl;
    file.close();
  } else {
    cout << "Unable to open file";
  }
}
void SportsInformation::GroupPlay()
{
  string line;
  ifstream file("GroupPlay");
  if (file.is_open()) {
    while (getline(file, line))
      cout << line << endl;
    file.close();
  } else {
    cout << "Unable to open file";
  }
}













class MatchReservation
{
public:
    void MatchPlace();
    void MatchDay();
    int Money();
private:
    int money;
    vector<string> reserv;
    vector<int> money_;
};
void MatchReservation::MatchDay()
{
    cout << "원하는 날짜를 고르세요" << endl;
}
void MatchReservation::MatchPlace()
{
    cout << "원하는 자리를 고르세요" << endl;
}
int MatchReservation::Money()
{
    cout << "자리마다 등급이 다릅니다. 선택하신 좌석은 - 입니다.";
    return money;
}










int main() {
  CreateAccount a;
  SportsInformation b;
  string line;
  while (1) {
    system("clear");
    string c;
    a.FirstPage();
    getline(cin, c);
    if(c == "1") //스포츠 정보 버튼 눌렀을 때
    {
        b.Sportspage();
        getline(cin,c);
        if(c == "1") // 경기 일정 및 개최지;
        {
            system("clear");
            b.KoreaList();
            sleep(5);
        }
        else if(c == "2") // 조별 리스트 명단;
        {
            system("clear");
            b.GroupList();
            sleep(5);
        }
        else if(c == "3") // 조별 경기 명단;
        {
            system("clear");
            b.GroupPlay();
            sleep(5);
        }
        else if(c == "4") // 한국 선수 팀 명단;
        {
            system("clear");
            b.KoreaList();
            sleep(5);
        }
    }
    else if (c == "2") // 경기 예매 버튼 눌렀을 때
    {
      a.SignUpPage(); // 로그인 페이지로 이동

      getline(cin, c);
      if(c == "1") //1. 로그인하기 눌렀을 때
      { 
        system("clear");
        //a.clear();
        cout << "ID를 입력하십시오 : ";
        getline(cin, line);
        // while (a.IdDu(line) == 0) {
        //   cout << "그런 ID는 없으니까 다시 하셈 : ";
        //   getline(cin, line);
        // }
        cout << "비밀번호를 입력하십시오 : ";
        getline(cin, line);
        // while (a.PwDu(line) == 0) {
        //   cout << "입력하신 비밀번호와 ID가 일치하지 않습니다. 다시 입력하셈 : ";
        //   getline(cin, line);
        // }
        cout << "로그인 되셨습니다!" << endl;
        a.ReservationPage();
      }
      else if(c == "2") //2. ID찾기 눌렀을 때
      {
        system("clear");
        a.PrintLogo();
        cout << "ID를 찾으려면? 어떠한 그런? 전화번호를 쳐보셈 : ";
        getline(cin,line);
        cout << "찾아낸 ID는 " << a.IdFind(line) << " 입니다." << endl;
        a.SignUpPage();
      }
      else if(c=="3") //3. 비밀번호 찾기 눌렀을 때
      {
        system("clear");
        a.PrintLogo();
        cout << "비밀번호를 찾으려면? 어떠한 그런? Id와 전화번호를 쳐보셈 ";
        cout << "ID : ";
        getline(cin,line);
        cout << "전화번호 : ";
        getline(cin,line);
        cout << "찾아낸 비밀번호는 " << a.PwFind(line) << " 입니다." << endl;
        a.SignUpPage();
      }
      else if (c == "4") // 4. 회원가입 버튼 눌렀을 때
      {
        system("clear");
        a.clear();
        cout << "ID를 입력하십시오 : ";
        getline(cin, line);
        while (a.IdDu(line) == 0) {
          cout << "모이치도! 모이치도! : ";
          getline(cin, line);
        }
        a.IdInput(line);

        cout << "비밀번호를 입력하십시오 : ";
        getline(cin, line);
        while (a.PwSet(line) == 0) {
          cout << "비밀번호는 5자 이상으로 입력해주세요. " << endl;
          getline(cin, line);
        }
        a.PwInput(line);

        cout << "이메일를 입력하십시오 : ";
        getline(cin, line);
        while (a.EmailDu(line) == 0) {
          cout << "모이치도! 모이치도! : ";
          getline(cin, line);
        }
        a.EmailInput(line);

        cout << "전화번호를 입력하십시오 : ";
        getline(cin, line);
        while (a.PhoneNumberDu(line) == 0) {
          cout << "모이치도! 모이치도! : ";
          getline(cin, line);
        }
        a.PhoneNumberInput(line);

        a.FileSave();
        cout << a.MemBerNumber() << "입니다.\n";
        a.FirstPage();
        //a.ShowResult();
      }
    }
  }
}
