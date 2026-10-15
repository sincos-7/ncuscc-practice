#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 四种设备的计数器和总小时数
    int printer_count = 0, printer_hours = 0;
    int scanner_count = 0, scanner_hours = 0;
    int router_count = 0, router_hours = 0;
    int server_count = 0, server_hours = 0;

    for (int i = 0; i < n; i++) {
        string type, status;
        int hours;
        cin >> type >> status >> hours;

        if (type == "printer") {
            printer_count++;
            printer_hours += hours;
        } else if (type == "scanner") {
            scanner_count++;
            scanner_hours += hours;
        } else if (type == "router") {
            router_count++;
            router_hours += hours;
        } else if (type == "server") {
            server_count++;
            server_hours += hours;
        }
    }

    // 输出前四行
    cout << "printer " << printer_count << " " << printer_hours << endl;
    cout << "scanner " << scanner_count << " " << scanner_hours << endl;
    cout << "router " << router_count << " " << router_hours << endl;
    cout << "server " << server_count << " " << server_hours << endl;

    // 找最忙的设备（按顺序比，先遇到大的就更新，平局时前面的保留）
    string busiest = "printer";
    int max_hours = printer_hours;

    if (scanner_hours > max_hours) {
        busiest = "scanner";
        max_hours = scanner_hours;
    }
    if (router_hours > max_hours) {
        busiest = "router";
        max_hours = router_hours;
    }
    if (server_hours > max_hours) {
        busiest = "server";
        max_hours = server_hours;
    }

    cout << "busiest " << busiest << endl;

    return 0;
}
