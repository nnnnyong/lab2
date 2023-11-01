#include <iostream>
#include <map>
#include <string>
#include <cstring>

struct Node {
    std::string name;
    int age;
    int scoreM;
    int scoreF;
};

int main() {
    int num_st;
    std::map<std::string, Node> studentMap;

    std::cout << "학생의 수를 입력 : ";
    std::cin >> num_st;

    for (int i = 0; i < num_st; ++i) {
        Node student;
        std::string name;
        std::cin >> name >> student.age >> student.scoreM >> student.scoreF;

        auto result = studentMap.insert(std::make_pair(name, student));
        if (result.second) {
            std::cout << "\"" << name << "\"님이 트리에 추가되었습니다." << std::endl;
        } else {
            std::cout << "\"" << name << "\"님이 트리에 이미 존재합니다." << std::endl;
        }
    }

    for (const auto& entry : studentMap) {
        std::cout << "이름 = " << entry.first << ", 나이 = " << entry.second.age
                  << ", 중간성적 = " << entry.second.scoreM << ", 기말성적 = " << entry.second.scoreF << std::endl;
    }

    return 0;
}

