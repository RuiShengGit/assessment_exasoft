#Refactor code

import os 
import re
from pathlib import Path

def getEnv(envVar):
    if envVar not in os.environ:
        raise EnvironmentError(f"{envVar} environment variable is not set")
    
    return os.environ[envVar]

def updateFile(filePath, pattern, replacement):
    # Ensure the file is writable (Not needed in modern systems)
    # os.chmod(filePath, 0o755)
    tempPath = filePath + ".tmp"
    updated = False

    with open(filePath, "r") as fin, open(tempPath, "w") as fout:
        for line in fin:
            newLine = re.sub(pattern, replacement, line)
            if newLine != line:
                updated = True
            fout.write(newLine)
            
    if not updated:
        raise ValueError(f"No matching pattern found in {filePath}")

    os.remove(filePath)
    os.rename(tempPath, filePath)


def main():
    sourcePath = Path(getEnv("SourcePath")) / "develop" / "global" / "src"
    sconstructPath = sourcePath / "SConstruct"
    versionPath = sourcePath / "VERSION"
    build_num = getEnv("BuildNum")

    updateFile(
        filePath=sconstructPath,
        pattern=r"point=\d+",
        replacement=f"point={build_num}"
    )

    updateFile(
        filePath=versionPath,
        pattern=r"ADLMSDK_VERSION_POINT=\d+",
        replacement=f"ADLMSDK_VERSION_POINT={build_num}"
    )

if __name__ == "__main__":
    main()