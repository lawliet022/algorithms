#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void __print(int x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HELLO
#define error(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define error(x...)
#endif


const int N = 1e5 + 10;

int cnt_project, cnt_person;

map<string,map<string,int>> personToSkill;          // for each person, map of skill to level
map<pair<string,int>,vector<string>> skillLevelToPerson;   // for each (skill, level) who all have this skill

map<string,map<string,int>> personToSkillCopy;          // for each person, map of skill to level
map<pair<string,int>,vector<string>> skillLevelToPersonCopy;   // for each (skill, level) who all have this skill

struct ProjectDetails {
  int duration, score, bestBefore, reqPersons;
  vector<pair<string,int>> skillLevel;
};

struct Project {
  string name;
  ProjectDetails projectDetails;
};

Project project[N];
map<string, ProjectDetails> projectMap;

struct ProjectAssigned {
  string projectName;
  vector<string> person;
};

long long scorer(vector<ProjectAssigned> &result) {
  long long ans = 0;
  map<string,map<string,int>> personToSkillNew;
  personToSkillNew = personToSkill;
  
  map<string,int> freeAt;  // person is free at time
  for (auto x : personToSkill) {
    freeAt[x.first] = 0;
  }
  
  int startTime = 0;
  
  for (auto assignedProject : result) {
    string project = assignedProject.projectName;
    assert((int)assignedProject.person.size() == projectMap[assignedProject.projectName].reqPersons);
    
    vector<pair<pair<string,string>,int>> req;
    map<string,int> extraSkill;
    
    for (int i = 0; i < (int)assignedProject.person.size(); i++) {
      
      string skill = projectMap[assignedProject.projectName].skillLevel[i].first;
      int level = projectMap[assignedProject.projectName].skillLevel[i].second;
      string person = assignedProject.person[i];
      
      startTime = max(startTime, freeAt[person]);
      
      for (auto xx : personToSkillNew[person]) {
        extraSkill[xx.first] = max(extraSkill[xx.first], xx.second);
      }
      
      if (personToSkill[person][skill] > level) {
        continue;
      }
      else if (personToSkillNew[person][skill] >= level - 1) {
        req.push_back({{skill, person}, level});
      } else {
        //error("** here ** ", project, personToSkillNew[person], skill, level);
        return -1;
      }
    }
    
    for (auto x : req) {
      if (extraSkill[x.first.first] < x.second) {
        return -1;
      }
      personToSkillNew[x.first.second][x.first.first]++;
    }
    //error(projectMap[project].score, projectMap[project].duration + startTime - projectMap[project].bestBefore);
    ans += max(0, projectMap[project].score - max(0, projectMap[project].duration + startTime - projectMap[project].bestBefore));
    for (auto x : assignedProject.person) {
      freeAt[x] = projectMap[project].duration + startTime;
    }
  }
  
  return ans;
}

vector<ProjectAssigned> finalAns;



int32_t main(){
  cin >> cnt_person >> cnt_project;
  for (int i = 0; i < cnt_person; i++) {
    string name;
    int skills;
    cin >> name >> skills;
    for (int j = 0; j < skills; j++) {
      string skill;
      int level;
      cin >> skill >> level;
      personToSkill[name][skill] = level;
      skillLevelToPerson[{skill, level}].push_back({name});
    }
  }
  
  for (int i = 0; i < cnt_project; i++) {
    ProjectDetails pd;
    string name;
    cin >> name >> pd.duration >> pd.score >> pd.bestBefore >> pd.reqPersons;
    for (int j = 0; j < pd.reqPersons; j++) {
      string skill;
      int level;
      cin >> skill >> level;
      pd.skillLevel.push_back({skill, level});
    }
    project[i].name = name;
    project[i].projectDetails = pd;
    projectMap[name] = pd;
  }
  
  personToSkillCopy = personToSkill;
  skillLevelToPersonCopy = skillLevelToPerson;
  
  int bestAns = 0;
  
  
  for (int iter = 100; iter <= 1000; iter += 10) {
    error(iter);
    sort(project, project + cnt_project, [&](Project &a, Project &b) {
      double xx = 1.0 * a.projectDetails.score / a.projectDetails.reqPersons;
      double yy = 1.0 * b.projectDetails.score / b.projectDetails.reqPersons;
      if (abs(xx - yy) > iter) {
        return xx > yy;
      } 
      return a.projectDetails.duration < b.projectDetails.duration;
    });
  
  
  map<string,int> timesUsed;
  
  vector<ProjectAssigned> ans;
  for (int i = 0; i < cnt_project; i++) {
    if (project[i].projectDetails.score < 3000) continue;
    vector<string> cur;
    string projectName = project[i].name;
    //error(projectName);
    set<string> used;
    for (auto x : project[i].projectDetails.skillLevel) {
       string best = "";
        int mini = 1e9;
      for (int k = x.second; k <= x.second + 100; k++) {
        if (skillLevelToPersonCopy.count({x.first, k})) {
          for (auto yy : skillLevelToPersonCopy[{x.first,k}]) {
            if (used.count(yy) == 0 && mini > timesUsed[yy]) {
              best = yy;
              mini = min(mini, timesUsed[yy]);
            }
          }
        }
      }
      if (best.size()) {
          cur.push_back(best);
          timesUsed[best]++;
          used.insert(best);
        }
    }
    if ((int)cur.size() == project[i].projectDetails.reqPersons) {
      ProjectAssigned p;
      p.projectName = projectName;
      p.person = cur;
      ans.push_back(p);
      //error(project[i].projectDetails.skillLevel, p.person);
    }
  }
  //cout << "Result\n";
  int curAns = scorer(ans);
  if (curAns > bestAns) {
    finalAns = ans;
    bestAns = max(bestAns, curAns);
  }    
  cerr << "Score : " << curAns << " " << bestAns << endl;
  }
  
  cout << finalAns.size() << endl;
    for (auto x : finalAns) {
      cout << x.projectName << endl;
      for (auto y : x.person) cout << y << " ";
      cout << endl;
    }
  
  
  
  return 0;
}























