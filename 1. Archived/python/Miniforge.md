Tag: #python 
Previous: 
Link: 

[TOC]

---

Miniforge is a minimal version of conda package manager. It allows you to install conda packages without needing to deal with anaconda.

# Installation

## Step 1: Find download link and download script

Find download link here: [miniforge - github](https://github.com/conda-forge/miniforge).

## Step 2: Execute installation script

```bash
# Assume that your script is downloaded to `Downloads` folder
cd Downloads/

# Run installation script. 
# The name of script may be different depending on your system.
sh Mambaforge-Linux-x86_64.sh
```

- Mambaforge will be installed into: `/home/littled3092/mambaforge`.
- CAUTION: If you entered `yes` when it prompts you whether you want to activate base environment, you may want to disable it by the following command:

```bash
conda config --set auto_activate_base false
```


## Step 3: Check installation

You can check installation by running the command `conda` or `mamba`. It will show some help message.

```bash
# Run 1 of the following
conda
mamba
```

- If `mamba` does not work but `conda` do, don't worry. It only means that `conda` is installed and `mamba` isn't. `mamba` can be installed using the following command:

```bash
conda install mamba -c conda-forge
```

---

# Reference

[miniforge - github](https://github.com/conda-forge/miniforge)
[How do I prevent conda from activating the base environment by default - stackoverflow](https://stackoverflow.com/questions/54429210/how-do-i-prevent-conda-from-activating-the-base-environment-by-default)

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.