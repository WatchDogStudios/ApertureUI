Get-ChildItem -Path 'tests/unit/*.c' | ForEach-Object {
    Get-Content $_.FullName | ForEach-Object {
        if ($_ -match 'SENTRY_TEST\(([^)]+)\)') {
            $_ -replace 'SENTRY_TEST\(([^)]+)\)', 'XX($1)'
        }
    }
} | Sort-Object | Where-Object { $_ -notmatch 'define' } | Get-Unique | Set-Content 'tests/unit/tests.inc'