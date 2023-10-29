# My-Vault
This is a note vault created to backup notes generated by obsidian.

# 1. Setup

```bash
$ git clone https://github.com/LittleD3092/My-Vault.git
```

Then use [obsidian](https://obsidian.md/) to open the folder as a vault.

Be aware that the attachments have great size, it is recommended that you use [Git LFS](https://github.com/LittleD3092/My-Vault#2-git-lfs) to speed cloning process.

# 2. Git LFS

This repository uses git lfs to manage files in `/附件`. It is recommended that git lfs is installed. See [git lfs installation - github](https://github.com/git-lfs/git-lfs/wiki/Installation) for installation.

## 2.1 Clone without Attachments

To clone this repository without attachments (pictures, videos, pdfs)

```bash
GIT_LFS_SKIP_SMUDGE=1 git clone https://github.com/LittleD3092/My-Vault.git
```

> [clone git repository without lfs files - stackoverflow](https://stackoverflow.com/questions/42019529/how-to-clone-pull-a-git-repository-ignoring-lfs)

## 2.2 Pull Attachments Missing

To pull attachments missing, use `git lfs pull --include=""` to pull single file, or simply use `git lfs pull` to pull all missing attachments

```bash
git lfs pull --include=filename
```

# 3. Entry Points

The lists of this section shows the root of some interesting topics.

## 3.1. Active

The list below shows the topics that are active and will be frequently added notes.

- [[Computer Graphics]]
- [[Database]]
- [[How to Make Good Notes]]
- [[Network Science]]
- [[Operating System]]
- [[SDN]]
- [[Sustainable Energy]]

## 3.2. Archived

The list below shows the topics that are archived and will not be frequently updated.

- [[Computer Networks Layers]]