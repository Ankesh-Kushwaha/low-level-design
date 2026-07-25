#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

class RequestInfo
{
  long long count;
  long long startWindow;

public:
  RequestInfo(long long c = 0, long long s = 0)
  {
    count = c;
    startWindow = s;
  }

  long long getReqCount() { return count; }
  long long getStartWindow() { return startWindow; }

  void setStartWindow(long long s) { startWindow = s; }
  void resetCount() { count = 0; }
  void incrementReq() { count++; }
};

class RateLimiter
{
  long long allowedReq;
  long long windowSize;
  unordered_map<string, RequestInfo> mp;

public:
  RateLimiter(long long a, long long w)
  {
    allowedReq = a;
    windowSize = w;
  }

  bool allowedRequest(string userId)
  {
    auto now = system_clock::now();
    long long currentTime =
        duration_cast<milliseconds>(now.time_since_epoch()).count();

    // If user not present, initialize
    if (!mp.count(userId))
    {
      mp[userId] = RequestInfo(0, currentTime);
    }

    RequestInfo &rq = mp[userId];

    // Check window expiration
    if (currentTime - rq.getStartWindow() > windowSize)
    {
      rq.setStartWindow(currentTime);
      rq.resetCount();
    }

    if (rq.getReqCount() < allowedReq)
    {
      rq.incrementReq();
      cout << "userId " << userId << " status: Request allowed\n";
      return true;
    }

    cout << "userId " << userId << " status: Request denied\n";
    return false;
  }
};

int main()
{
  RateLimiter rt(5, 10000);

  thread t1([&]()
           { rt.allowedRequest("ankesh"); });

  thread t2([&]()
           { rt.allowedRequest("ankesh"); });

  t1.join();
  t2.join();
  return 0;
}
