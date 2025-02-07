# C언어 레포지터리

- instagram : @old_cast1e

## tasks.json

### 개요

이 tasks.json 파일은 VS Code에서 C 및 C++ 프로그램을 빌드하고 실행하는 데 사용된다. 각 작업(Task)의 역할을 설명하고, 향후 사용 시 참고할 수 있도록 주석을 추가했다.
기본적인 C언어 빌드 및 컴파일 기능을 사용하기 위해 아래 json 코드를 사용한다.

- 현재 열려 있는 C 소스 파일을 Clang을 사용하여 컴파일하는 작업.
- -g 옵션을 사용하여 디버깅 정보를 포함한 바이너리 파일을 생성.
- ${file}: 현재 편집 중인 C 파일을 의미.
- -o ${fileDirname}/${fileBasenameNoExtension}: 출력 파일을 원본 소스 파일과 동일한 디렉토리에, 확장자를 제외한 파일명으로 저장.
- "cwd": "${workspaceRoot}": 현재 워크스페이스 디렉터리에서 작업 실행.
- "presentation": { "clear": true } → 이전 터미널 출력을 지우고 새로 실행.
- "group": "build" → 빌드 작업으로 분류.

- 실행 결과 : 컴파일된 실행 파일(main)이 현재 파일과 동일한 디렉토리에 생성됨.

```
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C build",
      "command": "clang",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceRoot}"
      },
      "presentation": {
        "clear": true
      },
      "group": "build",
      "problemMatcher": []
    },
    {
      "type": "shell",
      "label": "C compile",
      "command": "${fileDirname}/${fileBasenameNoExtension}",
      "group": "test",
      "presentation": {
        "clear": true
      }
    }
  ]
}

```

#### 개별 Task 설명

##### C 빌드 (clang 사용)

```json
{
  "type": "shell",
  "label": "C build",
  "command": "clang",
  "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
  "options": {
    "cwd": "${workspaceRoot}"
  },
  "presentation": {
    "clear": true
  },
  "group": "build",
  "problemMatcher": []
}
```

- clang을 사용하여 C 프로그램을 빌드한다.
- 현재 열려 있는 파일(${file})을 컴파일하여 실행 파일로 생성한다.
- 실행 파일은 현재 파일과 같은 디렉터리에 생성된다.

##### C++ 빌드 (clang++ 사용)

```json
{
  "type": "shell",
  "label": "C++ build for clang++",
  "command": "clang++",
  "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
  "options": {
    "cwd": "${workspaceRoot}"
  },
  "presentation": {
    "clear": true
  },
  "group": "build",
  "problemMatcher": []
}
```

- clang++을 사용하여 C++ 프로그램을 빌드한다.
- C build와 유사하지만, C++ 코드를 빌드하는 데 사용된다.

##### C 실행 (컴파일된 파일 실행)

```json
{
  "type": "shell",
  "label": "C compile",
  "command": "${fileDirname}/${fileBasenameNoExtension}",
  "group": "test",
  "presentation": {
    "clear": true
  }
}
```

- 컴파일된 C 프로그램을 실행한다.
- 실행할 파일은 현재 작업 중인 디렉터리에 위치해야 한다.

##### C/C++ 빌드 (clang 사용, VS Code 디버거에서 생성된 작업)

```json
{
  "type": "cppbuild",
  "label": "C/C++: clang 활성 파일 빌드",
  "command": "/usr/bin/clang",
  "args": [
    "-fcolor-diagnostics",
    "-fansi-escape-codes",
    "-g",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
  ],
  "options": {
    "cwd": "${fileDirname}"
  },
  "problemMatcher": ["$gcc"],
  "group": "build",
  "detail": "디버거에서 생성된 작업입니다."
}
```

- clang을 사용하여 C/C++ 프로그램을 빌드한다.
- clang의 다양한 진단 옵션(-fcolor-diagnostics, -fansi-escape-codes)을 포함한다.
- VS Code 디버거에서 자동 생성한 작업이다.

##### C/C++ 빌드 (gcc 사용, VS Code 디버거에서 생성된 작업)

```json
{
  "type": "cppbuild",
  "label": "C/C++: gcc 활성 파일 빌드",
  "command": "/usr/bin/gcc",
  "args": [
    "-fdiagnostics-color=always",
    "-g",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}",
    ""
  ],
  "options": {
    "cwd": "${fileDirname}"
  },
  "problemMatcher": ["$gcc"],
  "group": {
    "kind": "build",
    "isDefault": true
  },
  "detail": "디버거에서 생성된 작업입니다."
}
```

- gcc를 사용하여 C/C++ 프로그램을 빌드한다.
- 기본(isDefault: true) 빌드 태스크로 설정되어 있다.
- VS Code 디버거에서 자동 생성한 작업이다.

### 전체코드

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C build",
      "command": "clang",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceRoot}"
      },
      "presentation": {
        "clear": true
      },
      "group": "build",
      "problemMatcher": []
    },
    {
      "type": "shell",
      "label": "C++ build for clang++",
      "command": "clang++",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceRoot}"
      },
      "presentation": {
        "clear": true
      },
      "group": "build",
      "problemMatcher": []
    },
    {
      "type": "shell",
      "label": "C compile",
      "command": "${fileDirname}/${fileBasenameNoExtension}",
      "group": "test",
      "presentation": {
        "clear": true
      }
    },
    {
      "type": "cppbuild",
      "label": "C/C++: clang 활성 파일 빌드",
      "command": "/usr/bin/clang",
      "args": [
        "-fcolor-diagnostics",
        "-fansi-escape-codes",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": "build",
      "detail": "디버거에서 생성된 작업입니다."
    },
    {
      "type": "cppbuild",
      "label": "C/C++: gcc 활성 파일 빌드",
      "command": "/usr/bin/gcc",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}",
        ""
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "디버거에서 생성된 작업입니다."
    }
  ]
}
```
