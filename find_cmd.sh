grep -rn $1 . | grep -v "tester" | grep -v "main" | grep -v ".git" | grep -v "if(" | grep -v "return" | grep -v "="
