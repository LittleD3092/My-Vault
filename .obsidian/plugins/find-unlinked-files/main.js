'use strict';

var obsidian = require('obsidian');

/*! *****************************************************************************
Copyright (c) Microsoft Corporation.

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.
***************************************************************************** */
/* global Reflect, Promise */

var extendStatics = function(d, b) {
    extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
    return extendStatics(d, b);
};

function __extends(d, b) {
    if (typeof b !== "function" && b !== null)
        throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
    extendStatics(d, b);
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
}

function __awaiter(thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
}

function __generator(thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
}

/** @deprecated */
function __spreadArrays() {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
}

var DeleteFilesModal = /** @class */ (function (_super) {
    __extends(DeleteFilesModal, _super);
    function DeleteFilesModal(app, filesToDelete) {
        var _this = _super.call(this, app) || this;
        _this.filesToDelete = filesToDelete;
        return _this;
    }
    DeleteFilesModal.prototype.onOpen = function () {
        var _this = this;
        var _a = this, contentEl = _a.contentEl, titleEl = _a.titleEl;
        titleEl.setText('Move ' + this.filesToDelete.length + ' files to system trash?');
        contentEl
            .createEl("button", { text: "Cancel" })
            .addEventListener("click", function () { return _this.close(); });
        contentEl
            .setAttr("margin", "auto");
        contentEl
            .createEl("button", {
            cls: "mod-cta",
            text: "Confirm"
        })
            .addEventListener("click", function () { return __awaiter(_this, void 0, void 0, function () {
            var _i, _a, file;
            return __generator(this, function (_b) {
                switch (_b.label) {
                    case 0:
                        _i = 0, _a = this.filesToDelete;
                        _b.label = 1;
                    case 1:
                        if (!(_i < _a.length)) return [3 /*break*/, 4];
                        file = _a[_i];
                        return [4 /*yield*/, this.app.vault.trash(file, true)];
                    case 2:
                        _b.sent();
                        _b.label = 3;
                    case 3:
                        _i++;
                        return [3 /*break*/, 1];
                    case 4:
                        this.close();
                        return [2 /*return*/];
                }
            });
        }); });
    };
    DeleteFilesModal.prototype.onClose = function () {
        var contentEl = this.contentEl;
        contentEl.empty();
    };
    return DeleteFilesModal;
}(obsidian.Modal));

var SettingsTab = /** @class */ (function (_super) {
    __extends(SettingsTab, _super);
    function SettingsTab(app, plugin, defaultSettings) {
        var _this = _super.call(this, app, plugin) || this;
        _this.defaultSettings = defaultSettings;
        _this.plugin = plugin;
        return _this;
    }
    SettingsTab.prototype.formatPath = function (path, addDirectorySlash) {
        if (path.length == 0)
            return path;
        path = obsidian.normalizePath(path);
        if (addDirectorySlash)
            return path + "/";
        else
            return path;
    };
    SettingsTab.prototype.display = function () {
        var _this = this;
        var containerEl = this.containerEl;
        containerEl.empty();
        containerEl.createEl("h2", { text: this.plugin.manifest.name });
        containerEl.createEl("h4", { text: "Settings for find unlinked files" });
        new obsidian.Setting(containerEl)
            .setName('Output file name')
            .setDesc('Set name of output file (without file extension). Make sure no file exists with this name because it will be overwritten! If the name is empty, the default name is set.')
            .addText(function (cb) { return cb.onChange(function (value) {
            if (value.length == 0) {
                _this.plugin.settings.outputFileName = _this.defaultSettings.outputFileName;
            }
            else {
                _this.plugin.settings.outputFileName = value;
            }
            _this.plugin.saveSettings();
        }).setValue(_this.plugin.settings.outputFileName); });
        new obsidian.Setting(containerEl)
            .setName('Disable working links')
            .setDesc('Indent lines to disable the link and to clean up the graph view')
            .addToggle(function (cb) { return cb.onChange(function (value) {
            _this.plugin.settings.disableWorkingLinks = value;
            _this.plugin.saveSettings();
        }).setValue(_this.plugin.settings.disableWorkingLinks); });
        new obsidian.Setting(containerEl)
            .setName("Ignore or include files in the given directories")
            .setDesc("Enable to ignore files in the given directories. Disable to only include files in the given directories")
            .addToggle(function (cb) {
            return cb.setValue(_this.plugin.settings.ignoreDirectories)
                .onChange(function (value) {
                _this.plugin.settings.ignoreDirectories = value;
                _this.plugin.saveSettings();
            });
        });
        new obsidian.Setting(containerEl)
            .setName("Directories")
            .setDesc("Add each directory path in a new line")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/Subdirectory")
            .setValue(_this.plugin.settings.directoriesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, true); });
            _this.plugin.settings.directoriesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Files to ignore.")
            .setDesc("Add each file path in a new line (with file extension!)")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/file.md")
            .setValue(_this.plugin.settings.filesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, false); });
            _this.plugin.settings.filesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Links to ignore.")
            .setDesc("Ignore files, which contain the given file as link. Add each file path in a new line (with file extension!). Set it to `*` to ignore files with links.")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/file.md")
            .setValue(_this.plugin.settings.linksToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, false); });
            _this.plugin.settings.linksToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Ignore or include files with the given filetypes")
            .setDesc("Enable to ignore files with the given filetypes. Disable to only include files with the given filetypes")
            .addToggle(function (cb) {
            return cb.setValue(_this.plugin.settings.ignoreFileTypes)
                .onChange(function (value) {
                _this.plugin.settings.ignoreFileTypes = value;
                _this.plugin.saveSettings();
            });
        });
        new obsidian.Setting(containerEl)
            .setName("File types")
            .setDesc("Effect depends on toggle above")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("docx,txt")
            .setValue(_this.plugin.settings.fileTypesToIgnore.join(","))
            .onChange(function (value) {
            var extensions = value.trim().split(",");
            _this.plugin.settings.fileTypesToIgnore = extensions;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Tags to ignore.")
            .setDesc("Ignore files, which contain the given tag. Add each tag separated by comma (without `#`)")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("todo,unfinished")
            .setValue(_this.plugin.settings.tagsToIgnore.join(","))
            .onChange(function (value) {
            var tags = value.trim().split(",");
            _this.plugin.settings.tagsToIgnore = tags;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Filetypes to delete per command. See README.")
            .setDesc("Add each filetype separated by comma. Set to `*` to delete all files.")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("jpg,png")
            .setValue(_this.plugin.settings.fileTypesToDelete.join(","))
            .onChange(function (value) {
            var extensions = value.trim().split(",");
            _this.plugin.settings.fileTypesToDelete = extensions;
            _this.plugin.saveSettings();
        }); });
        /// Settings for find unresolvedLinks
        containerEl.createEl("h4", { text: "Settings for find unresolved links" });
        new obsidian.Setting(containerEl)
            .setName('Output file name')
            .setDesc('Set name of output file (without file extension). Make sure no file exists with this name because it will be overwritten! If the name is empty, the default name is set.')
            .addText(function (cb) { return cb.onChange(function (value) {
            if (value.length == 0) {
                _this.plugin.settings.unresolvedLinksOutputFileName = _this.defaultSettings.unresolvedLinksOutputFileName;
            }
            else {
                _this.plugin.settings.unresolvedLinksOutputFileName = value;
            }
            _this.plugin.saveSettings();
        }).setValue(_this.plugin.settings.unresolvedLinksOutputFileName); });
        new obsidian.Setting(containerEl)
            .setName("Directories to ignore.")
            .setDesc("Ignore links in files in the specified directory. Add each directory path in a new line")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/Subdirectory")
            .setValue(_this.plugin.settings.unresolvedLinksDirectoriesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, true); });
            _this.plugin.settings.unresolvedLinksDirectoriesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Files to ignore.")
            .setDesc("Ignore links in the specified file. Add each file path in a new line (with file extension!)")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/file.md")
            .setValue(_this.plugin.settings.unresolvedLinksFilesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, false); });
            _this.plugin.settings.unresolvedLinksFilesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Links to ignore.")
            .setDesc("Ignore files, which contain the given file as link. Add each file path in a new line (with file extension!). Set it to `*` to ignore files with links.")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/file.md")
            .setValue(_this.plugin.settings.unresolvedLinksLinksToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, false); });
            _this.plugin.settings.unresolvedLinksLinksToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Filetypes to ignore.")
            .setDesc("Ignore links with the specified filetype. Add each filetype separated by comma")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("docx,txt")
            .setValue(_this.plugin.settings.unresolvedLinksFileTypesToIgnore.join(","))
            .onChange(function (value) {
            var extensions = value.trim().split(",");
            _this.plugin.settings.unresolvedLinksFileTypesToIgnore = extensions;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Tags to ignore.")
            .setDesc("Ignore links in files, which contain the given tag. Add each tag separated by comma (without `#`)")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("todo,unfinished")
            .setValue(_this.plugin.settings.unresolvedLinksTagsToIgnore.join(","))
            .onChange(function (value) {
            var tags = value.trim().split(",");
            _this.plugin.settings.unresolvedLinksTagsToIgnore = tags;
            _this.plugin.saveSettings();
        }); });
        containerEl.createEl("h4", { text: "Settings for find files without tags" });
        new obsidian.Setting(containerEl)
            .setName('Output file name')
            .setDesc('Set name of output file (without file extension). Make sure no file exists with this name because it will be overwritten! If the name is empty, the default name is set.')
            .addText(function (cb) { return cb.onChange(function (value) {
            if (value.length == 0) {
                _this.plugin.settings.withoutTagsOutputFileName = _this.defaultSettings.withoutTagsOutputFileName;
            }
            else {
                _this.plugin.settings.withoutTagsOutputFileName = value;
            }
            _this.plugin.saveSettings();
        }).setValue(_this.plugin.settings.withoutTagsOutputFileName); });
        new obsidian.Setting(containerEl)
            .setName("Files to ignore.")
            .setDesc("Ignore the specific files. Add each file path in a new line (with file extension!)")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/file.md")
            .setValue(_this.plugin.settings.withoutTagsFilesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, false); });
            _this.plugin.settings.withoutTagsFilesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
        new obsidian.Setting(containerEl)
            .setName("Directories to ignore.")
            .setDesc("Ignore files in the specified directories. Add each directory path in a new line")
            .addTextArea(function (cb) { return cb
            .setPlaceholder("Directory/Subdirectory")
            .setValue(_this.plugin.settings.withoutTagsDirectoriesToIgnore.join("\n"))
            .onChange(function (value) {
            var paths = value.trim().split("\n").map(function (value) { return _this.formatPath(value, true); });
            _this.plugin.settings.withoutTagsDirectoriesToIgnore = paths;
            _this.plugin.saveSettings();
        }); });
    };
    return SettingsTab;
}(obsidian.PluginSettingTab));

var Utils = /** @class */ (function () {
    /**
     * Checks for the given settings. Is used for `Find unlinked files` and `Find unresolved links`
     * @param app
     * @param filePath
     * @param tagsToIgnore
     * @param linksToIgnore
     * @param directoriesToIgnore
     * @param filesToIgnore
     * @param ignoreDirectories
     */
    function Utils(app, filePath, tagsToIgnore, linksToIgnore, directoriesToIgnore, filesToIgnore, ignoreDirectories) {
        if (ignoreDirectories === void 0) { ignoreDirectories = true; }
        this.app = app;
        this.filePath = filePath;
        this.tagsToIgnore = tagsToIgnore;
        this.linksToIgnore = linksToIgnore;
        this.directoriesToIgnore = directoriesToIgnore;
        this.filesToIgnore = filesToIgnore;
        this.ignoreDirectories = ignoreDirectories;
        this.fileCache = app.metadataCache.getCache(filePath);
    }
    Utils.prototype.hasTagsToIgnore = function () {
        var _this = this;
        var tags = obsidian.getAllTags(this.fileCache);
        return (tags === null || tags === void 0 ? void 0 : tags.find(function (tag) { return _this.tagsToIgnore.contains(tag.substring(1)); })) !== undefined;
    };
    Utils.prototype.hasLinksToIgnore = function () {
        var _this = this;
        var _a, _b;
        if ((((_a = this.fileCache) === null || _a === void 0 ? void 0 : _a.embeds) != null || ((_b = this.fileCache) === null || _b === void 0 ? void 0 : _b.links) != null) && this.linksToIgnore[0] == "*") {
            return true;
        }
        return obsidian.iterateCacheRefs(this.fileCache, function (cb) {
            var _a;
            var link = (_a = _this.app.metadataCache.getFirstLinkpathDest(cb.link, _this.filePath)) === null || _a === void 0 ? void 0 : _a.path;
            return _this.linksToIgnore.contains(link);
        });
    };
    Utils.prototype.checkDirectory = function () {
        var _this = this;
        var contains = this.directoriesToIgnore.find(function (value) { return _this.filePath.startsWith(value) && value.length != 0; }) !== undefined;
        if (this.ignoreDirectories) {
            return contains;
        }
        else {
            return !contains;
        }
    };
    Utils.prototype.isFileToIgnore = function () {
        return this.filesToIgnore.contains(this.filePath);
    };
    Utils.prototype.isValid = function () {
        return !this.hasTagsToIgnore() && !this.hasLinksToIgnore() && !this.checkDirectory() && !this.isFileToIgnore();
    };
    /**
     * Writes the text to the file and opens the file in a new pane if it is not opened yet
     * @param app
     * @param outputFileName name of the output file
     * @param text data to be written to the file
     */
    Utils.writeAndOpenFile = function (app, outputFileName, text) {
        return __awaiter(this, void 0, void 0, function () {
            var fileIsAlreadyOpened;
            return __generator(this, function (_a) {
                switch (_a.label) {
                    case 0: return [4 /*yield*/, app.vault.adapter.write(outputFileName, text)];
                    case 1:
                        _a.sent();
                        fileIsAlreadyOpened = false;
                        app.workspace.iterateAllLeaves(function (leaf) {
                            if (leaf.getDisplayText() != "" && outputFileName.startsWith(leaf.getDisplayText())) {
                                fileIsAlreadyOpened = true;
                            }
                        });
                        if (!fileIsAlreadyOpened)
                            app.workspace.openLinkText(outputFileName, "/", true);
                        return [2 /*return*/];
                }
            });
        });
    };
    return Utils;
}());

var DEFAULT_SETTINGS = {
    outputFileName: "unlinked files output",
    disableWorkingLinks: false,
    directoriesToIgnore: [],
    filesToIgnore: [],
    fileTypesToIgnore: [],
    linksToIgnore: [],
    tagsToIgnore: [],
    fileTypesToDelete: [],
    ignoreFileTypes: true,
    ignoreDirectories: true,
    unresolvedLinksOutputFileName: "unresolved links output",
    unresolvedLinksDirectoriesToIgnore: [],
    unresolvedLinksFilesToIgnore: [],
    unresolvedLinksFileTypesToIgnore: [],
    unresolvedLinksLinksToIgnore: [],
    unresolvedLinksTagsToIgnore: [],
    withoutTagsDirectoriesToIgnore: [],
    withoutTagsFilesToIgnore: [],
    withoutTagsOutputFileName: "files without tags"
};
var FindUnlinkedFilesPlugin = /** @class */ (function (_super) {
    __extends(FindUnlinkedFilesPlugin, _super);
    function FindUnlinkedFilesPlugin() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    FindUnlinkedFilesPlugin.prototype.onload = function () {
        return __awaiter(this, void 0, void 0, function () {
            var _this = this;
            return __generator(this, function (_a) {
                switch (_a.label) {
                    case 0:
                        console.log('loading ' + this.manifest.name + " plugin");
                        return [4 /*yield*/, this.loadSettings()];
                    case 1:
                        _a.sent();
                        this.addCommand({
                            id: 'find-unlinked-files',
                            name: 'Find unlinked files',
                            callback: function () { return _this.findUnlinkedFiles(); },
                        });
                        this.addCommand({
                            id: 'find-unresolved-link',
                            name: 'Find unresolved links',
                            callback: function () { return _this.findUnresolvedLinks(); },
                        });
                        this.addCommand({
                            id: "delete-unlinked-files",
                            name: "Delete unlinked files with certain extension. See README",
                            callback: function () { return _this.deleteUnlinkedFiles(); }
                        });
                        this.addCommand({
                            id: "find-files-without-tags",
                            name: "Find files without tags",
                            callback: function () { return _this.findFilesWithoutTags(); }
                        });
                        this.addSettingTab(new SettingsTab(this.app, this, DEFAULT_SETTINGS));
                        return [2 /*return*/];
                }
            });
        });
    };
    FindUnlinkedFilesPlugin.prototype.findUnlinkedFiles = function () {
        var _this = this;
        var outFileName = this.settings.outputFileName + ".md";
        var outFile;
        var files = this.app.vault.getFiles();
        var markdownFiles = this.app.vault.getMarkdownFiles();
        var links = [];
        markdownFiles.forEach(function (markFile) {
            if (markFile.path == outFileName) {
                outFile = markFile;
                return;
            }
            obsidian.iterateCacheRefs(_this.app.metadataCache.getFileCache(markFile), function (cb) {
                var txt = _this.app.metadataCache.getFirstLinkpathDest(obsidian.getLinkpath(cb.link), markFile.path);
                if (txt != null)
                    links.push(txt.path);
            });
        });
        var notLinkedFiles = files.filter(function (file) { return _this.isValid(file, links); });
        notLinkedFiles.remove(outFile);
        var text = "";
        var prefix;
        if (this.settings.disableWorkingLinks)
            prefix = "	";
        else
            prefix = "";
        notLinkedFiles.forEach(function (file) {
            text += prefix + "- [[" + _this.app.metadataCache.fileToLinktext(file, "/") + "]]\n";
        });
        Utils.writeAndOpenFile(this.app, outFileName, text);
    };
    FindUnlinkedFilesPlugin.prototype.deleteUnlinkedFiles = function () {
        var _a, _b;
        return __awaiter(this, void 0, void 0, function () {
            var links, filesToDelete;
            var _this = this;
            return __generator(this, function (_c) {
                switch (_c.label) {
                    case 0: return [4 /*yield*/, this.app.vault.adapter.exists(this.settings.outputFileName + ".md")];
                    case 1:
                        if (!(_c.sent())) {
                            new obsidian.Notice("Can't find file - Please run the `Find unlinked files' command before");
                            return [2 /*return*/];
                        }
                        links = (_b = (_a = this.app.metadataCache.getCache(this.settings.outputFileName + ".md")) === null || _a === void 0 ? void 0 : _a.links) !== null && _b !== void 0 ? _b : [];
                        filesToDelete = [];
                        console.log(this.settings.fileTypesToDelete);
                        links.forEach(function (link) {
                            var file = _this.app.metadataCache.getFirstLinkpathDest(link.link, "/");
                            if (!file)
                                return;
                            if (_this.settings.fileTypesToDelete[0] == "*" || _this.settings.fileTypesToDelete.contains(file.extension)) {
                                filesToDelete.push(file);
                            }
                        });
                        if (filesToDelete.length > 0)
                            new DeleteFilesModal(this.app, filesToDelete).open();
                        return [2 /*return*/];
                }
            });
        });
    };
    FindUnlinkedFilesPlugin.prototype.findUnresolvedLinks = function () {
        var outFileName = this.settings.unresolvedLinksOutputFileName + ".md";
        var links = [];
        var unresolvedLinks = this.app.metadataCache.unresolvedLinks;
        for (var filePath in unresolvedLinks) {
            if (filePath == this.settings.unresolvedLinksOutputFileName + ".md")
                continue;
            var fileType = filePath.substring(filePath.lastIndexOf(".") + 1);
            var utils = new Utils(this.app, filePath, this.settings.unresolvedLinksTagsToIgnore, this.settings.unresolvedLinksLinksToIgnore, this.settings.unresolvedLinksDirectoriesToIgnore, this.settings.unresolvedLinksFilesToIgnore);
            if (!utils.isValid())
                continue;
            var _loop_1 = function (link) {
                var linkFileType = link.substring(link.lastIndexOf(".") + 1);
                console.log(linkFileType);
                if (this_1.settings.unresolvedLinksFileTypesToIgnore.contains(linkFileType))
                    return "continue";
                var formattedFilePath = filePath;
                if (fileType == "md") {
                    formattedFilePath = filePath.substring(0, filePath.lastIndexOf(".md"));
                }
                var unresolvedLink = { files: [formattedFilePath], link: link };
                if (links.contains(unresolvedLink))
                    return "continue";
                var duplication = links.find(function (e) { return e.link == link; });
                if (duplication) {
                    duplication.files.push(formattedFilePath);
                }
                else {
                    links.push(unresolvedLink);
                }
            };
            var this_1 = this;
            for (var link in unresolvedLinks[filePath]) {
                _loop_1(link);
            }
        }
        Utils.writeAndOpenFile(this.app, outFileName, __spreadArrays([
            "Don't forget that creating the file from here may create the file in the wrong directory!"
        ], links.map(function (e) { return "- [[" + e.link + "]] in [[" + e.files.join("]], [[") + "]]"; })).join("\n"));
    };
    FindUnlinkedFilesPlugin.prototype.findFilesWithoutTags = function () {
        var _this = this;
        var outFileName = this.settings.withoutTagsOutputFileName + ".md";
        var outFile;
        var files = this.app.vault.getMarkdownFiles();
        var withoutFiles = files.filter(function (file) {
            var _a;
            if (new Utils(_this.app, file.path, [], [], _this.settings.withoutTagsDirectoriesToIgnore, _this.settings.withoutTagsFilesToIgnore, true).isValid()) {
                return ((_a = obsidian.getAllTags(_this.app.metadataCache.getFileCache(file)).length) !== null && _a !== void 0 ? _a : 0) <= 0;
            }
            else {
                return false;
            }
        });
        withoutFiles.remove(outFile);
        var prefix;
        if (this.settings.disableWorkingLinks)
            prefix = "	";
        else
            prefix = "";
        var text = withoutFiles.map(function (file) { return prefix + "- [[" + file.path + "]]"; }).join("\n");
        Utils.writeAndOpenFile(this.app, outFileName, text);
    };
    /**
     * Checks if the given file in an unlinked file
     *
     * @param file file to check
     * @param links all links in the vault
     */
    FindUnlinkedFilesPlugin.prototype.isValid = function (file, links) {
        if (links.contains(file.path))
            return false;
        //filetypes to ignore by default
        if (file.extension == "css")
            return false;
        if (this.settings.fileTypesToIgnore[0] !== "") {
            var containsFileType = this.settings.fileTypesToIgnore.contains(file.extension);
            if (this.settings.ignoreFileTypes) {
                if (containsFileType)
                    return;
            }
            else {
                if (!containsFileType)
                    return;
            }
        }
        var utils = new Utils(this.app, file.path, this.settings.tagsToIgnore, this.settings.linksToIgnore, this.settings.directoriesToIgnore, this.settings.filesToIgnore, this.settings.ignoreDirectories);
        if (!utils.isValid())
            return false;
        return true;
    };
    FindUnlinkedFilesPlugin.prototype.onunload = function () {
        console.log('unloading ' + this.manifest.name + " plugin");
    };
    FindUnlinkedFilesPlugin.prototype.loadSettings = function () {
        return __awaiter(this, void 0, void 0, function () {
            var _a, _b, _c, _d;
            return __generator(this, function (_e) {
                switch (_e.label) {
                    case 0:
                        _a = this;
                        _c = (_b = Object).assign;
                        _d = [DEFAULT_SETTINGS];
                        return [4 /*yield*/, this.loadData()];
                    case 1:
                        _a.settings = _c.apply(_b, _d.concat([_e.sent()]));
                        return [2 /*return*/];
                }
            });
        });
    };
    FindUnlinkedFilesPlugin.prototype.saveSettings = function () {
        return __awaiter(this, void 0, void 0, function () {
            return __generator(this, function (_a) {
                switch (_a.label) {
                    case 0: return [4 /*yield*/, this.saveData(this.settings)];
                    case 1:
                        _a.sent();
                        return [2 /*return*/];
                }
            });
        });
    };
    return FindUnlinkedFilesPlugin;
}(obsidian.Plugin));

module.exports = FindUnlinkedFilesPlugin;
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoibWFpbi5qcyIsInNvdXJjZXMiOlsibm9kZV9tb2R1bGVzL3RzbGliL3RzbGliLmVzNi5qcyIsInNyYy9kZWxldGVGaWxlc01vZGFsLnRzIiwic3JjL3NldHRpbmdzVGFiLnRzIiwic3JjL3V0aWxzLnRzIiwic3JjL21haW4udHMiXSwic291cmNlc0NvbnRlbnQiOlsiLyohICoqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqXHJcbkNvcHlyaWdodCAoYykgTWljcm9zb2Z0IENvcnBvcmF0aW9uLlxyXG5cclxuUGVybWlzc2lvbiB0byB1c2UsIGNvcHksIG1vZGlmeSwgYW5kL29yIGRpc3RyaWJ1dGUgdGhpcyBzb2Z0d2FyZSBmb3IgYW55XHJcbnB1cnBvc2Ugd2l0aCBvciB3aXRob3V0IGZlZSBpcyBoZXJlYnkgZ3JhbnRlZC5cclxuXHJcblRIRSBTT0ZUV0FSRSBJUyBQUk9WSURFRCBcIkFTIElTXCIgQU5EIFRIRSBBVVRIT1IgRElTQ0xBSU1TIEFMTCBXQVJSQU5USUVTIFdJVEhcclxuUkVHQVJEIFRPIFRISVMgU09GVFdBUkUgSU5DTFVESU5HIEFMTCBJTVBMSUVEIFdBUlJBTlRJRVMgT0YgTUVSQ0hBTlRBQklMSVRZXHJcbkFORCBGSVRORVNTLiBJTiBOTyBFVkVOVCBTSEFMTCBUSEUgQVVUSE9SIEJFIExJQUJMRSBGT1IgQU5ZIFNQRUNJQUwsIERJUkVDVCxcclxuSU5ESVJFQ1QsIE9SIENPTlNFUVVFTlRJQUwgREFNQUdFUyBPUiBBTlkgREFNQUdFUyBXSEFUU09FVkVSIFJFU1VMVElORyBGUk9NXHJcbkxPU1MgT0YgVVNFLCBEQVRBIE9SIFBST0ZJVFMsIFdIRVRIRVIgSU4gQU4gQUNUSU9OIE9GIENPTlRSQUNULCBORUdMSUdFTkNFIE9SXHJcbk9USEVSIFRPUlRJT1VTIEFDVElPTiwgQVJJU0lORyBPVVQgT0YgT1IgSU4gQ09OTkVDVElPTiBXSVRIIFRIRSBVU0UgT1JcclxuUEVSRk9STUFOQ0UgT0YgVEhJUyBTT0ZUV0FSRS5cclxuKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKioqKiogKi9cclxuLyogZ2xvYmFsIFJlZmxlY3QsIFByb21pc2UgKi9cclxuXHJcbnZhciBleHRlbmRTdGF0aWNzID0gZnVuY3Rpb24oZCwgYikge1xyXG4gICAgZXh0ZW5kU3RhdGljcyA9IE9iamVjdC5zZXRQcm90b3R5cGVPZiB8fFxyXG4gICAgICAgICh7IF9fcHJvdG9fXzogW10gfSBpbnN0YW5jZW9mIEFycmF5ICYmIGZ1bmN0aW9uIChkLCBiKSB7IGQuX19wcm90b19fID0gYjsgfSkgfHxcclxuICAgICAgICBmdW5jdGlvbiAoZCwgYikgeyBmb3IgKHZhciBwIGluIGIpIGlmIChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwoYiwgcCkpIGRbcF0gPSBiW3BdOyB9O1xyXG4gICAgcmV0dXJuIGV4dGVuZFN0YXRpY3MoZCwgYik7XHJcbn07XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19leHRlbmRzKGQsIGIpIHtcclxuICAgIGlmICh0eXBlb2YgYiAhPT0gXCJmdW5jdGlvblwiICYmIGIgIT09IG51bGwpXHJcbiAgICAgICAgdGhyb3cgbmV3IFR5cGVFcnJvcihcIkNsYXNzIGV4dGVuZHMgdmFsdWUgXCIgKyBTdHJpbmcoYikgKyBcIiBpcyBub3QgYSBjb25zdHJ1Y3RvciBvciBudWxsXCIpO1xyXG4gICAgZXh0ZW5kU3RhdGljcyhkLCBiKTtcclxuICAgIGZ1bmN0aW9uIF9fKCkgeyB0aGlzLmNvbnN0cnVjdG9yID0gZDsgfVxyXG4gICAgZC5wcm90b3R5cGUgPSBiID09PSBudWxsID8gT2JqZWN0LmNyZWF0ZShiKSA6IChfXy5wcm90b3R5cGUgPSBiLnByb3RvdHlwZSwgbmV3IF9fKCkpO1xyXG59XHJcblxyXG5leHBvcnQgdmFyIF9fYXNzaWduID0gZnVuY3Rpb24oKSB7XHJcbiAgICBfX2Fzc2lnbiA9IE9iamVjdC5hc3NpZ24gfHwgZnVuY3Rpb24gX19hc3NpZ24odCkge1xyXG4gICAgICAgIGZvciAodmFyIHMsIGkgPSAxLCBuID0gYXJndW1lbnRzLmxlbmd0aDsgaSA8IG47IGkrKykge1xyXG4gICAgICAgICAgICBzID0gYXJndW1lbnRzW2ldO1xyXG4gICAgICAgICAgICBmb3IgKHZhciBwIGluIHMpIGlmIChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwocywgcCkpIHRbcF0gPSBzW3BdO1xyXG4gICAgICAgIH1cclxuICAgICAgICByZXR1cm4gdDtcclxuICAgIH1cclxuICAgIHJldHVybiBfX2Fzc2lnbi5hcHBseSh0aGlzLCBhcmd1bWVudHMpO1xyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19yZXN0KHMsIGUpIHtcclxuICAgIHZhciB0ID0ge307XHJcbiAgICBmb3IgKHZhciBwIGluIHMpIGlmIChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwocywgcCkgJiYgZS5pbmRleE9mKHApIDwgMClcclxuICAgICAgICB0W3BdID0gc1twXTtcclxuICAgIGlmIChzICE9IG51bGwgJiYgdHlwZW9mIE9iamVjdC5nZXRPd25Qcm9wZXJ0eVN5bWJvbHMgPT09IFwiZnVuY3Rpb25cIilcclxuICAgICAgICBmb3IgKHZhciBpID0gMCwgcCA9IE9iamVjdC5nZXRPd25Qcm9wZXJ0eVN5bWJvbHMocyk7IGkgPCBwLmxlbmd0aDsgaSsrKSB7XHJcbiAgICAgICAgICAgIGlmIChlLmluZGV4T2YocFtpXSkgPCAwICYmIE9iamVjdC5wcm90b3R5cGUucHJvcGVydHlJc0VudW1lcmFibGUuY2FsbChzLCBwW2ldKSlcclxuICAgICAgICAgICAgICAgIHRbcFtpXV0gPSBzW3BbaV1dO1xyXG4gICAgICAgIH1cclxuICAgIHJldHVybiB0O1xyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19kZWNvcmF0ZShkZWNvcmF0b3JzLCB0YXJnZXQsIGtleSwgZGVzYykge1xyXG4gICAgdmFyIGMgPSBhcmd1bWVudHMubGVuZ3RoLCByID0gYyA8IDMgPyB0YXJnZXQgOiBkZXNjID09PSBudWxsID8gZGVzYyA9IE9iamVjdC5nZXRPd25Qcm9wZXJ0eURlc2NyaXB0b3IodGFyZ2V0LCBrZXkpIDogZGVzYywgZDtcclxuICAgIGlmICh0eXBlb2YgUmVmbGVjdCA9PT0gXCJvYmplY3RcIiAmJiB0eXBlb2YgUmVmbGVjdC5kZWNvcmF0ZSA9PT0gXCJmdW5jdGlvblwiKSByID0gUmVmbGVjdC5kZWNvcmF0ZShkZWNvcmF0b3JzLCB0YXJnZXQsIGtleSwgZGVzYyk7XHJcbiAgICBlbHNlIGZvciAodmFyIGkgPSBkZWNvcmF0b3JzLmxlbmd0aCAtIDE7IGkgPj0gMDsgaS0tKSBpZiAoZCA9IGRlY29yYXRvcnNbaV0pIHIgPSAoYyA8IDMgPyBkKHIpIDogYyA+IDMgPyBkKHRhcmdldCwga2V5LCByKSA6IGQodGFyZ2V0LCBrZXkpKSB8fCByO1xyXG4gICAgcmV0dXJuIGMgPiAzICYmIHIgJiYgT2JqZWN0LmRlZmluZVByb3BlcnR5KHRhcmdldCwga2V5LCByKSwgcjtcclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fcGFyYW0ocGFyYW1JbmRleCwgZGVjb3JhdG9yKSB7XHJcbiAgICByZXR1cm4gZnVuY3Rpb24gKHRhcmdldCwga2V5KSB7IGRlY29yYXRvcih0YXJnZXQsIGtleSwgcGFyYW1JbmRleCk7IH1cclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fbWV0YWRhdGEobWV0YWRhdGFLZXksIG1ldGFkYXRhVmFsdWUpIHtcclxuICAgIGlmICh0eXBlb2YgUmVmbGVjdCA9PT0gXCJvYmplY3RcIiAmJiB0eXBlb2YgUmVmbGVjdC5tZXRhZGF0YSA9PT0gXCJmdW5jdGlvblwiKSByZXR1cm4gUmVmbGVjdC5tZXRhZGF0YShtZXRhZGF0YUtleSwgbWV0YWRhdGFWYWx1ZSk7XHJcbn1cclxuXHJcbmV4cG9ydCBmdW5jdGlvbiBfX2F3YWl0ZXIodGhpc0FyZywgX2FyZ3VtZW50cywgUCwgZ2VuZXJhdG9yKSB7XHJcbiAgICBmdW5jdGlvbiBhZG9wdCh2YWx1ZSkgeyByZXR1cm4gdmFsdWUgaW5zdGFuY2VvZiBQID8gdmFsdWUgOiBuZXcgUChmdW5jdGlvbiAocmVzb2x2ZSkgeyByZXNvbHZlKHZhbHVlKTsgfSk7IH1cclxuICAgIHJldHVybiBuZXcgKFAgfHwgKFAgPSBQcm9taXNlKSkoZnVuY3Rpb24gKHJlc29sdmUsIHJlamVjdCkge1xyXG4gICAgICAgIGZ1bmN0aW9uIGZ1bGZpbGxlZCh2YWx1ZSkgeyB0cnkgeyBzdGVwKGdlbmVyYXRvci5uZXh0KHZhbHVlKSk7IH0gY2F0Y2ggKGUpIHsgcmVqZWN0KGUpOyB9IH1cclxuICAgICAgICBmdW5jdGlvbiByZWplY3RlZCh2YWx1ZSkgeyB0cnkgeyBzdGVwKGdlbmVyYXRvcltcInRocm93XCJdKHZhbHVlKSk7IH0gY2F0Y2ggKGUpIHsgcmVqZWN0KGUpOyB9IH1cclxuICAgICAgICBmdW5jdGlvbiBzdGVwKHJlc3VsdCkgeyByZXN1bHQuZG9uZSA/IHJlc29sdmUocmVzdWx0LnZhbHVlKSA6IGFkb3B0KHJlc3VsdC52YWx1ZSkudGhlbihmdWxmaWxsZWQsIHJlamVjdGVkKTsgfVxyXG4gICAgICAgIHN0ZXAoKGdlbmVyYXRvciA9IGdlbmVyYXRvci5hcHBseSh0aGlzQXJnLCBfYXJndW1lbnRzIHx8IFtdKSkubmV4dCgpKTtcclxuICAgIH0pO1xyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19nZW5lcmF0b3IodGhpc0FyZywgYm9keSkge1xyXG4gICAgdmFyIF8gPSB7IGxhYmVsOiAwLCBzZW50OiBmdW5jdGlvbigpIHsgaWYgKHRbMF0gJiAxKSB0aHJvdyB0WzFdOyByZXR1cm4gdFsxXTsgfSwgdHJ5czogW10sIG9wczogW10gfSwgZiwgeSwgdCwgZztcclxuICAgIHJldHVybiBnID0geyBuZXh0OiB2ZXJiKDApLCBcInRocm93XCI6IHZlcmIoMSksIFwicmV0dXJuXCI6IHZlcmIoMikgfSwgdHlwZW9mIFN5bWJvbCA9PT0gXCJmdW5jdGlvblwiICYmIChnW1N5bWJvbC5pdGVyYXRvcl0gPSBmdW5jdGlvbigpIHsgcmV0dXJuIHRoaXM7IH0pLCBnO1xyXG4gICAgZnVuY3Rpb24gdmVyYihuKSB7IHJldHVybiBmdW5jdGlvbiAodikgeyByZXR1cm4gc3RlcChbbiwgdl0pOyB9OyB9XHJcbiAgICBmdW5jdGlvbiBzdGVwKG9wKSB7XHJcbiAgICAgICAgaWYgKGYpIHRocm93IG5ldyBUeXBlRXJyb3IoXCJHZW5lcmF0b3IgaXMgYWxyZWFkeSBleGVjdXRpbmcuXCIpO1xyXG4gICAgICAgIHdoaWxlIChfKSB0cnkge1xyXG4gICAgICAgICAgICBpZiAoZiA9IDEsIHkgJiYgKHQgPSBvcFswXSAmIDIgPyB5W1wicmV0dXJuXCJdIDogb3BbMF0gPyB5W1widGhyb3dcIl0gfHwgKCh0ID0geVtcInJldHVyblwiXSkgJiYgdC5jYWxsKHkpLCAwKSA6IHkubmV4dCkgJiYgISh0ID0gdC5jYWxsKHksIG9wWzFdKSkuZG9uZSkgcmV0dXJuIHQ7XHJcbiAgICAgICAgICAgIGlmICh5ID0gMCwgdCkgb3AgPSBbb3BbMF0gJiAyLCB0LnZhbHVlXTtcclxuICAgICAgICAgICAgc3dpdGNoIChvcFswXSkge1xyXG4gICAgICAgICAgICAgICAgY2FzZSAwOiBjYXNlIDE6IHQgPSBvcDsgYnJlYWs7XHJcbiAgICAgICAgICAgICAgICBjYXNlIDQ6IF8ubGFiZWwrKzsgcmV0dXJuIHsgdmFsdWU6IG9wWzFdLCBkb25lOiBmYWxzZSB9O1xyXG4gICAgICAgICAgICAgICAgY2FzZSA1OiBfLmxhYmVsKys7IHkgPSBvcFsxXTsgb3AgPSBbMF07IGNvbnRpbnVlO1xyXG4gICAgICAgICAgICAgICAgY2FzZSA3OiBvcCA9IF8ub3BzLnBvcCgpOyBfLnRyeXMucG9wKCk7IGNvbnRpbnVlO1xyXG4gICAgICAgICAgICAgICAgZGVmYXVsdDpcclxuICAgICAgICAgICAgICAgICAgICBpZiAoISh0ID0gXy50cnlzLCB0ID0gdC5sZW5ndGggPiAwICYmIHRbdC5sZW5ndGggLSAxXSkgJiYgKG9wWzBdID09PSA2IHx8IG9wWzBdID09PSAyKSkgeyBfID0gMDsgY29udGludWU7IH1cclxuICAgICAgICAgICAgICAgICAgICBpZiAob3BbMF0gPT09IDMgJiYgKCF0IHx8IChvcFsxXSA+IHRbMF0gJiYgb3BbMV0gPCB0WzNdKSkpIHsgXy5sYWJlbCA9IG9wWzFdOyBicmVhazsgfVxyXG4gICAgICAgICAgICAgICAgICAgIGlmIChvcFswXSA9PT0gNiAmJiBfLmxhYmVsIDwgdFsxXSkgeyBfLmxhYmVsID0gdFsxXTsgdCA9IG9wOyBicmVhazsgfVxyXG4gICAgICAgICAgICAgICAgICAgIGlmICh0ICYmIF8ubGFiZWwgPCB0WzJdKSB7IF8ubGFiZWwgPSB0WzJdOyBfLm9wcy5wdXNoKG9wKTsgYnJlYWs7IH1cclxuICAgICAgICAgICAgICAgICAgICBpZiAodFsyXSkgXy5vcHMucG9wKCk7XHJcbiAgICAgICAgICAgICAgICAgICAgXy50cnlzLnBvcCgpOyBjb250aW51ZTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICBvcCA9IGJvZHkuY2FsbCh0aGlzQXJnLCBfKTtcclxuICAgICAgICB9IGNhdGNoIChlKSB7IG9wID0gWzYsIGVdOyB5ID0gMDsgfSBmaW5hbGx5IHsgZiA9IHQgPSAwOyB9XHJcbiAgICAgICAgaWYgKG9wWzBdICYgNSkgdGhyb3cgb3BbMV07IHJldHVybiB7IHZhbHVlOiBvcFswXSA/IG9wWzFdIDogdm9pZCAwLCBkb25lOiB0cnVlIH07XHJcbiAgICB9XHJcbn1cclxuXHJcbmV4cG9ydCB2YXIgX19jcmVhdGVCaW5kaW5nID0gT2JqZWN0LmNyZWF0ZSA/IChmdW5jdGlvbihvLCBtLCBrLCBrMikge1xyXG4gICAgaWYgKGsyID09PSB1bmRlZmluZWQpIGsyID0gaztcclxuICAgIE9iamVjdC5kZWZpbmVQcm9wZXJ0eShvLCBrMiwgeyBlbnVtZXJhYmxlOiB0cnVlLCBnZXQ6IGZ1bmN0aW9uKCkgeyByZXR1cm4gbVtrXTsgfSB9KTtcclxufSkgOiAoZnVuY3Rpb24obywgbSwgaywgazIpIHtcclxuICAgIGlmIChrMiA9PT0gdW5kZWZpbmVkKSBrMiA9IGs7XHJcbiAgICBvW2syXSA9IG1ba107XHJcbn0pO1xyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fZXhwb3J0U3RhcihtLCBvKSB7XHJcbiAgICBmb3IgKHZhciBwIGluIG0pIGlmIChwICE9PSBcImRlZmF1bHRcIiAmJiAhT2JqZWN0LnByb3RvdHlwZS5oYXNPd25Qcm9wZXJ0eS5jYWxsKG8sIHApKSBfX2NyZWF0ZUJpbmRpbmcobywgbSwgcCk7XHJcbn1cclxuXHJcbmV4cG9ydCBmdW5jdGlvbiBfX3ZhbHVlcyhvKSB7XHJcbiAgICB2YXIgcyA9IHR5cGVvZiBTeW1ib2wgPT09IFwiZnVuY3Rpb25cIiAmJiBTeW1ib2wuaXRlcmF0b3IsIG0gPSBzICYmIG9bc10sIGkgPSAwO1xyXG4gICAgaWYgKG0pIHJldHVybiBtLmNhbGwobyk7XHJcbiAgICBpZiAobyAmJiB0eXBlb2Ygby5sZW5ndGggPT09IFwibnVtYmVyXCIpIHJldHVybiB7XHJcbiAgICAgICAgbmV4dDogZnVuY3Rpb24gKCkge1xyXG4gICAgICAgICAgICBpZiAobyAmJiBpID49IG8ubGVuZ3RoKSBvID0gdm9pZCAwO1xyXG4gICAgICAgICAgICByZXR1cm4geyB2YWx1ZTogbyAmJiBvW2krK10sIGRvbmU6ICFvIH07XHJcbiAgICAgICAgfVxyXG4gICAgfTtcclxuICAgIHRocm93IG5ldyBUeXBlRXJyb3IocyA/IFwiT2JqZWN0IGlzIG5vdCBpdGVyYWJsZS5cIiA6IFwiU3ltYm9sLml0ZXJhdG9yIGlzIG5vdCBkZWZpbmVkLlwiKTtcclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fcmVhZChvLCBuKSB7XHJcbiAgICB2YXIgbSA9IHR5cGVvZiBTeW1ib2wgPT09IFwiZnVuY3Rpb25cIiAmJiBvW1N5bWJvbC5pdGVyYXRvcl07XHJcbiAgICBpZiAoIW0pIHJldHVybiBvO1xyXG4gICAgdmFyIGkgPSBtLmNhbGwobyksIHIsIGFyID0gW10sIGU7XHJcbiAgICB0cnkge1xyXG4gICAgICAgIHdoaWxlICgobiA9PT0gdm9pZCAwIHx8IG4tLSA+IDApICYmICEociA9IGkubmV4dCgpKS5kb25lKSBhci5wdXNoKHIudmFsdWUpO1xyXG4gICAgfVxyXG4gICAgY2F0Y2ggKGVycm9yKSB7IGUgPSB7IGVycm9yOiBlcnJvciB9OyB9XHJcbiAgICBmaW5hbGx5IHtcclxuICAgICAgICB0cnkge1xyXG4gICAgICAgICAgICBpZiAociAmJiAhci5kb25lICYmIChtID0gaVtcInJldHVyblwiXSkpIG0uY2FsbChpKTtcclxuICAgICAgICB9XHJcbiAgICAgICAgZmluYWxseSB7IGlmIChlKSB0aHJvdyBlLmVycm9yOyB9XHJcbiAgICB9XHJcbiAgICByZXR1cm4gYXI7XHJcbn1cclxuXHJcbi8qKiBAZGVwcmVjYXRlZCAqL1xyXG5leHBvcnQgZnVuY3Rpb24gX19zcHJlYWQoKSB7XHJcbiAgICBmb3IgKHZhciBhciA9IFtdLCBpID0gMDsgaSA8IGFyZ3VtZW50cy5sZW5ndGg7IGkrKylcclxuICAgICAgICBhciA9IGFyLmNvbmNhdChfX3JlYWQoYXJndW1lbnRzW2ldKSk7XHJcbiAgICByZXR1cm4gYXI7XHJcbn1cclxuXHJcbi8qKiBAZGVwcmVjYXRlZCAqL1xyXG5leHBvcnQgZnVuY3Rpb24gX19zcHJlYWRBcnJheXMoKSB7XHJcbiAgICBmb3IgKHZhciBzID0gMCwgaSA9IDAsIGlsID0gYXJndW1lbnRzLmxlbmd0aDsgaSA8IGlsOyBpKyspIHMgKz0gYXJndW1lbnRzW2ldLmxlbmd0aDtcclxuICAgIGZvciAodmFyIHIgPSBBcnJheShzKSwgayA9IDAsIGkgPSAwOyBpIDwgaWw7IGkrKylcclxuICAgICAgICBmb3IgKHZhciBhID0gYXJndW1lbnRzW2ldLCBqID0gMCwgamwgPSBhLmxlbmd0aDsgaiA8IGpsOyBqKyssIGsrKylcclxuICAgICAgICAgICAgcltrXSA9IGFbal07XHJcbiAgICByZXR1cm4gcjtcclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fc3ByZWFkQXJyYXkodG8sIGZyb20sIHBhY2spIHtcclxuICAgIGlmIChwYWNrIHx8IGFyZ3VtZW50cy5sZW5ndGggPT09IDIpIGZvciAodmFyIGkgPSAwLCBsID0gZnJvbS5sZW5ndGgsIGFyOyBpIDwgbDsgaSsrKSB7XHJcbiAgICAgICAgaWYgKGFyIHx8ICEoaSBpbiBmcm9tKSkge1xyXG4gICAgICAgICAgICBpZiAoIWFyKSBhciA9IEFycmF5LnByb3RvdHlwZS5zbGljZS5jYWxsKGZyb20sIDAsIGkpO1xyXG4gICAgICAgICAgICBhcltpXSA9IGZyb21baV07XHJcbiAgICAgICAgfVxyXG4gICAgfVxyXG4gICAgcmV0dXJuIHRvLmNvbmNhdChhciB8fCBBcnJheS5wcm90b3R5cGUuc2xpY2UuY2FsbChmcm9tKSk7XHJcbn1cclxuXHJcbmV4cG9ydCBmdW5jdGlvbiBfX2F3YWl0KHYpIHtcclxuICAgIHJldHVybiB0aGlzIGluc3RhbmNlb2YgX19hd2FpdCA/ICh0aGlzLnYgPSB2LCB0aGlzKSA6IG5ldyBfX2F3YWl0KHYpO1xyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19hc3luY0dlbmVyYXRvcih0aGlzQXJnLCBfYXJndW1lbnRzLCBnZW5lcmF0b3IpIHtcclxuICAgIGlmICghU3ltYm9sLmFzeW5jSXRlcmF0b3IpIHRocm93IG5ldyBUeXBlRXJyb3IoXCJTeW1ib2wuYXN5bmNJdGVyYXRvciBpcyBub3QgZGVmaW5lZC5cIik7XHJcbiAgICB2YXIgZyA9IGdlbmVyYXRvci5hcHBseSh0aGlzQXJnLCBfYXJndW1lbnRzIHx8IFtdKSwgaSwgcSA9IFtdO1xyXG4gICAgcmV0dXJuIGkgPSB7fSwgdmVyYihcIm5leHRcIiksIHZlcmIoXCJ0aHJvd1wiKSwgdmVyYihcInJldHVyblwiKSwgaVtTeW1ib2wuYXN5bmNJdGVyYXRvcl0gPSBmdW5jdGlvbiAoKSB7IHJldHVybiB0aGlzOyB9LCBpO1xyXG4gICAgZnVuY3Rpb24gdmVyYihuKSB7IGlmIChnW25dKSBpW25dID0gZnVuY3Rpb24gKHYpIHsgcmV0dXJuIG5ldyBQcm9taXNlKGZ1bmN0aW9uIChhLCBiKSB7IHEucHVzaChbbiwgdiwgYSwgYl0pID4gMSB8fCByZXN1bWUobiwgdik7IH0pOyB9OyB9XHJcbiAgICBmdW5jdGlvbiByZXN1bWUobiwgdikgeyB0cnkgeyBzdGVwKGdbbl0odikpOyB9IGNhdGNoIChlKSB7IHNldHRsZShxWzBdWzNdLCBlKTsgfSB9XHJcbiAgICBmdW5jdGlvbiBzdGVwKHIpIHsgci52YWx1ZSBpbnN0YW5jZW9mIF9fYXdhaXQgPyBQcm9taXNlLnJlc29sdmUoci52YWx1ZS52KS50aGVuKGZ1bGZpbGwsIHJlamVjdCkgOiBzZXR0bGUocVswXVsyXSwgcik7IH1cclxuICAgIGZ1bmN0aW9uIGZ1bGZpbGwodmFsdWUpIHsgcmVzdW1lKFwibmV4dFwiLCB2YWx1ZSk7IH1cclxuICAgIGZ1bmN0aW9uIHJlamVjdCh2YWx1ZSkgeyByZXN1bWUoXCJ0aHJvd1wiLCB2YWx1ZSk7IH1cclxuICAgIGZ1bmN0aW9uIHNldHRsZShmLCB2KSB7IGlmIChmKHYpLCBxLnNoaWZ0KCksIHEubGVuZ3RoKSByZXN1bWUocVswXVswXSwgcVswXVsxXSk7IH1cclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fYXN5bmNEZWxlZ2F0b3Iobykge1xyXG4gICAgdmFyIGksIHA7XHJcbiAgICByZXR1cm4gaSA9IHt9LCB2ZXJiKFwibmV4dFwiKSwgdmVyYihcInRocm93XCIsIGZ1bmN0aW9uIChlKSB7IHRocm93IGU7IH0pLCB2ZXJiKFwicmV0dXJuXCIpLCBpW1N5bWJvbC5pdGVyYXRvcl0gPSBmdW5jdGlvbiAoKSB7IHJldHVybiB0aGlzOyB9LCBpO1xyXG4gICAgZnVuY3Rpb24gdmVyYihuLCBmKSB7IGlbbl0gPSBvW25dID8gZnVuY3Rpb24gKHYpIHsgcmV0dXJuIChwID0gIXApID8geyB2YWx1ZTogX19hd2FpdChvW25dKHYpKSwgZG9uZTogbiA9PT0gXCJyZXR1cm5cIiB9IDogZiA/IGYodikgOiB2OyB9IDogZjsgfVxyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19hc3luY1ZhbHVlcyhvKSB7XHJcbiAgICBpZiAoIVN5bWJvbC5hc3luY0l0ZXJhdG9yKSB0aHJvdyBuZXcgVHlwZUVycm9yKFwiU3ltYm9sLmFzeW5jSXRlcmF0b3IgaXMgbm90IGRlZmluZWQuXCIpO1xyXG4gICAgdmFyIG0gPSBvW1N5bWJvbC5hc3luY0l0ZXJhdG9yXSwgaTtcclxuICAgIHJldHVybiBtID8gbS5jYWxsKG8pIDogKG8gPSB0eXBlb2YgX192YWx1ZXMgPT09IFwiZnVuY3Rpb25cIiA/IF9fdmFsdWVzKG8pIDogb1tTeW1ib2wuaXRlcmF0b3JdKCksIGkgPSB7fSwgdmVyYihcIm5leHRcIiksIHZlcmIoXCJ0aHJvd1wiKSwgdmVyYihcInJldHVyblwiKSwgaVtTeW1ib2wuYXN5bmNJdGVyYXRvcl0gPSBmdW5jdGlvbiAoKSB7IHJldHVybiB0aGlzOyB9LCBpKTtcclxuICAgIGZ1bmN0aW9uIHZlcmIobikgeyBpW25dID0gb1tuXSAmJiBmdW5jdGlvbiAodikgeyByZXR1cm4gbmV3IFByb21pc2UoZnVuY3Rpb24gKHJlc29sdmUsIHJlamVjdCkgeyB2ID0gb1tuXSh2KSwgc2V0dGxlKHJlc29sdmUsIHJlamVjdCwgdi5kb25lLCB2LnZhbHVlKTsgfSk7IH07IH1cclxuICAgIGZ1bmN0aW9uIHNldHRsZShyZXNvbHZlLCByZWplY3QsIGQsIHYpIHsgUHJvbWlzZS5yZXNvbHZlKHYpLnRoZW4oZnVuY3Rpb24odikgeyByZXNvbHZlKHsgdmFsdWU6IHYsIGRvbmU6IGQgfSk7IH0sIHJlamVjdCk7IH1cclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fbWFrZVRlbXBsYXRlT2JqZWN0KGNvb2tlZCwgcmF3KSB7XHJcbiAgICBpZiAoT2JqZWN0LmRlZmluZVByb3BlcnR5KSB7IE9iamVjdC5kZWZpbmVQcm9wZXJ0eShjb29rZWQsIFwicmF3XCIsIHsgdmFsdWU6IHJhdyB9KTsgfSBlbHNlIHsgY29va2VkLnJhdyA9IHJhdzsgfVxyXG4gICAgcmV0dXJuIGNvb2tlZDtcclxufTtcclxuXHJcbnZhciBfX3NldE1vZHVsZURlZmF1bHQgPSBPYmplY3QuY3JlYXRlID8gKGZ1bmN0aW9uKG8sIHYpIHtcclxuICAgIE9iamVjdC5kZWZpbmVQcm9wZXJ0eShvLCBcImRlZmF1bHRcIiwgeyBlbnVtZXJhYmxlOiB0cnVlLCB2YWx1ZTogdiB9KTtcclxufSkgOiBmdW5jdGlvbihvLCB2KSB7XHJcbiAgICBvW1wiZGVmYXVsdFwiXSA9IHY7XHJcbn07XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19pbXBvcnRTdGFyKG1vZCkge1xyXG4gICAgaWYgKG1vZCAmJiBtb2QuX19lc01vZHVsZSkgcmV0dXJuIG1vZDtcclxuICAgIHZhciByZXN1bHQgPSB7fTtcclxuICAgIGlmIChtb2QgIT0gbnVsbCkgZm9yICh2YXIgayBpbiBtb2QpIGlmIChrICE9PSBcImRlZmF1bHRcIiAmJiBPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwobW9kLCBrKSkgX19jcmVhdGVCaW5kaW5nKHJlc3VsdCwgbW9kLCBrKTtcclxuICAgIF9fc2V0TW9kdWxlRGVmYXVsdChyZXN1bHQsIG1vZCk7XHJcbiAgICByZXR1cm4gcmVzdWx0O1xyXG59XHJcblxyXG5leHBvcnQgZnVuY3Rpb24gX19pbXBvcnREZWZhdWx0KG1vZCkge1xyXG4gICAgcmV0dXJuIChtb2QgJiYgbW9kLl9fZXNNb2R1bGUpID8gbW9kIDogeyBkZWZhdWx0OiBtb2QgfTtcclxufVxyXG5cclxuZXhwb3J0IGZ1bmN0aW9uIF9fY2xhc3NQcml2YXRlRmllbGRHZXQocmVjZWl2ZXIsIHN0YXRlLCBraW5kLCBmKSB7XHJcbiAgICBpZiAoa2luZCA9PT0gXCJhXCIgJiYgIWYpIHRocm93IG5ldyBUeXBlRXJyb3IoXCJQcml2YXRlIGFjY2Vzc29yIHdhcyBkZWZpbmVkIHdpdGhvdXQgYSBnZXR0ZXJcIik7XHJcbiAgICBpZiAodHlwZW9mIHN0YXRlID09PSBcImZ1bmN0aW9uXCIgPyByZWNlaXZlciAhPT0gc3RhdGUgfHwgIWYgOiAhc3RhdGUuaGFzKHJlY2VpdmVyKSkgdGhyb3cgbmV3IFR5cGVFcnJvcihcIkNhbm5vdCByZWFkIHByaXZhdGUgbWVtYmVyIGZyb20gYW4gb2JqZWN0IHdob3NlIGNsYXNzIGRpZCBub3QgZGVjbGFyZSBpdFwiKTtcclxuICAgIHJldHVybiBraW5kID09PSBcIm1cIiA/IGYgOiBraW5kID09PSBcImFcIiA/IGYuY2FsbChyZWNlaXZlcikgOiBmID8gZi52YWx1ZSA6IHN0YXRlLmdldChyZWNlaXZlcik7XHJcbn1cclxuXHJcbmV4cG9ydCBmdW5jdGlvbiBfX2NsYXNzUHJpdmF0ZUZpZWxkU2V0KHJlY2VpdmVyLCBzdGF0ZSwgdmFsdWUsIGtpbmQsIGYpIHtcclxuICAgIGlmIChraW5kID09PSBcIm1cIikgdGhyb3cgbmV3IFR5cGVFcnJvcihcIlByaXZhdGUgbWV0aG9kIGlzIG5vdCB3cml0YWJsZVwiKTtcclxuICAgIGlmIChraW5kID09PSBcImFcIiAmJiAhZikgdGhyb3cgbmV3IFR5cGVFcnJvcihcIlByaXZhdGUgYWNjZXNzb3Igd2FzIGRlZmluZWQgd2l0aG91dCBhIHNldHRlclwiKTtcclxuICAgIGlmICh0eXBlb2Ygc3RhdGUgPT09IFwiZnVuY3Rpb25cIiA/IHJlY2VpdmVyICE9PSBzdGF0ZSB8fCAhZiA6ICFzdGF0ZS5oYXMocmVjZWl2ZXIpKSB0aHJvdyBuZXcgVHlwZUVycm9yKFwiQ2Fubm90IHdyaXRlIHByaXZhdGUgbWVtYmVyIHRvIGFuIG9iamVjdCB3aG9zZSBjbGFzcyBkaWQgbm90IGRlY2xhcmUgaXRcIik7XHJcbiAgICByZXR1cm4gKGtpbmQgPT09IFwiYVwiID8gZi5jYWxsKHJlY2VpdmVyLCB2YWx1ZSkgOiBmID8gZi52YWx1ZSA9IHZhbHVlIDogc3RhdGUuc2V0KHJlY2VpdmVyLCB2YWx1ZSkpLCB2YWx1ZTtcclxufVxyXG4iLCJpbXBvcnQgeyBBcHAsIE1vZGFsLCBURmlsZSB9IGZyb20gJ29ic2lkaWFuJztcblxuZXhwb3J0IGNsYXNzIERlbGV0ZUZpbGVzTW9kYWwgZXh0ZW5kcyBNb2RhbCB7XG5cdGZpbGVzVG9EZWxldGU6IFRGaWxlW107XG5cdGNvbnN0cnVjdG9yKGFwcDogQXBwLCBmaWxlc1RvRGVsZXRlOiBURmlsZVtdKSB7XG5cdFx0c3VwZXIoYXBwKTtcblx0XHR0aGlzLmZpbGVzVG9EZWxldGUgPSBmaWxlc1RvRGVsZXRlO1xuXHR9XG5cblx0b25PcGVuKCkge1xuXHRcdGxldCB7IGNvbnRlbnRFbCwgdGl0bGVFbCB9ID0gdGhpcztcblx0XHR0aXRsZUVsLnNldFRleHQoJ01vdmUgJyArIHRoaXMuZmlsZXNUb0RlbGV0ZS5sZW5ndGggKyAnIGZpbGVzIHRvIHN5c3RlbSB0cmFzaD8nKTtcblx0XHRjb250ZW50RWxcblx0XHRcdC5jcmVhdGVFbChcImJ1dHRvblwiLCB7IHRleHQ6IFwiQ2FuY2VsXCIgfSlcblx0XHRcdC5hZGRFdmVudExpc3RlbmVyKFwiY2xpY2tcIiwgKCkgPT4gdGhpcy5jbG9zZSgpKTtcblx0XHRjb250ZW50RWxcblx0XHRcdC5zZXRBdHRyKFwibWFyZ2luXCIsIFwiYXV0b1wiKTtcblxuXHRcdGNvbnRlbnRFbFxuXHRcdFx0LmNyZWF0ZUVsKFwiYnV0dG9uXCIsXG5cdFx0XHRcdHtcblx0XHRcdFx0XHRjbHM6IFwibW9kLWN0YVwiLFxuXHRcdFx0XHRcdHRleHQ6IFwiQ29uZmlybVwiXG5cdFx0XHRcdH0pXG5cdFx0XHQuYWRkRXZlbnRMaXN0ZW5lcihcImNsaWNrXCIsIGFzeW5jICgpID0+IHtcblx0XHRcdFx0Zm9yIChjb25zdCBmaWxlIG9mIHRoaXMuZmlsZXNUb0RlbGV0ZSkge1xuXHRcdFx0XHRcdGF3YWl0IHRoaXMuYXBwLnZhdWx0LnRyYXNoKGZpbGUsIHRydWUpO1xuXHRcdFx0XHR9XG5cdFx0XHRcdHRoaXMuY2xvc2UoKTtcblx0XHRcdH0pO1xuXG5cdH1cblxuXHRvbkNsb3NlKCkge1xuXHRcdGxldCB7IGNvbnRlbnRFbCB9ID0gdGhpcztcblx0XHRjb250ZW50RWwuZW1wdHkoKTtcblx0fVxufVxuIiwiaW1wb3J0IHsgQXBwLCBub3JtYWxpemVQYXRoLCBQbHVnaW5TZXR0aW5nVGFiLCBTZXR0aW5nIH0gZnJvbSAnb2JzaWRpYW4nO1xuaW1wb3J0IEZpbmRVbmxpbmtlZEZpbGVzUGx1Z2luLCB7IFNldHRpbmdzIH0gZnJvbSAnLi9tYWluJztcblxuZXhwb3J0IGNsYXNzIFNldHRpbmdzVGFiIGV4dGVuZHMgUGx1Z2luU2V0dGluZ1RhYiB7XG4gICAgcGx1Z2luOiBGaW5kVW5saW5rZWRGaWxlc1BsdWdpbjtcbiAgICBjb25zdHJ1Y3RvcihhcHA6IEFwcCwgcGx1Z2luOiBGaW5kVW5saW5rZWRGaWxlc1BsdWdpbiwgcHJpdmF0ZSBkZWZhdWx0U2V0dGluZ3M6IFNldHRpbmdzKSB7XG4gICAgICAgIHN1cGVyKGFwcCwgcGx1Z2luKTtcbiAgICAgICAgdGhpcy5wbHVnaW4gPSBwbHVnaW47XG4gICAgfVxuICAgIGZvcm1hdFBhdGgocGF0aDogc3RyaW5nLCBhZGREaXJlY3RvcnlTbGFzaDogYm9vbGVhbik6IHN0cmluZyB7XG4gICAgICAgIGlmIChwYXRoLmxlbmd0aCA9PSAwKVxuICAgICAgICAgICAgcmV0dXJuIHBhdGg7XG4gICAgICAgIHBhdGggPSBub3JtYWxpemVQYXRoKHBhdGgpO1xuICAgICAgICBpZiAoYWRkRGlyZWN0b3J5U2xhc2gpXG4gICAgICAgICAgICByZXR1cm4gcGF0aCArIFwiL1wiO1xuICAgICAgICBlbHNlXG4gICAgICAgICAgICByZXR1cm4gcGF0aDtcbiAgICB9XG5cbiAgICBkaXNwbGF5KCk6IHZvaWQge1xuICAgICAgICBsZXQgeyBjb250YWluZXJFbCB9ID0gdGhpcztcbiAgICAgICAgY29udGFpbmVyRWwuZW1wdHkoKTtcbiAgICAgICAgY29udGFpbmVyRWwuY3JlYXRlRWwoXCJoMlwiLCB7IHRleHQ6IHRoaXMucGx1Z2luLm1hbmlmZXN0Lm5hbWUgfSk7XG5cbiAgICAgICAgY29udGFpbmVyRWwuY3JlYXRlRWwoXCJoNFwiLCB7IHRleHQ6IFwiU2V0dGluZ3MgZm9yIGZpbmQgdW5saW5rZWQgZmlsZXNcIiB9KTtcbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZSgnT3V0cHV0IGZpbGUgbmFtZScpXG4gICAgICAgICAgICAuc2V0RGVzYygnU2V0IG5hbWUgb2Ygb3V0cHV0IGZpbGUgKHdpdGhvdXQgZmlsZSBleHRlbnNpb24pLiBNYWtlIHN1cmUgbm8gZmlsZSBleGlzdHMgd2l0aCB0aGlzIG5hbWUgYmVjYXVzZSBpdCB3aWxsIGJlIG92ZXJ3cml0dGVuISBJZiB0aGUgbmFtZSBpcyBlbXB0eSwgdGhlIGRlZmF1bHQgbmFtZSBpcyBzZXQuJylcbiAgICAgICAgICAgIC5hZGRUZXh0KGNiID0+IGNiLm9uQ2hhbmdlKHZhbHVlID0+IHtcbiAgICAgICAgICAgICAgICBpZiAodmFsdWUubGVuZ3RoID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3Mub3V0cHV0RmlsZU5hbWUgPSB0aGlzLmRlZmF1bHRTZXR0aW5ncy5vdXRwdXRGaWxlTmFtZTtcbiAgICAgICAgICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy5vdXRwdXRGaWxlTmFtZSA9IHZhbHVlO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgIH0pLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLm91dHB1dEZpbGVOYW1lKSk7XG5cbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZSgnRGlzYWJsZSB3b3JraW5nIGxpbmtzJylcbiAgICAgICAgICAgIC5zZXREZXNjKCdJbmRlbnQgbGluZXMgdG8gZGlzYWJsZSB0aGUgbGluayBhbmQgdG8gY2xlYW4gdXAgdGhlIGdyYXBoIHZpZXcnKVxuICAgICAgICAgICAgLmFkZFRvZ2dsZShjYiA9PiBjYi5vbkNoYW5nZSh2YWx1ZSA9PiB7XG4gICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MuZGlzYWJsZVdvcmtpbmdMaW5rcyA9IHZhbHVlO1xuICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNhdmVTZXR0aW5ncygpO1xuICAgICAgICAgICAgfVxuICAgICAgICAgICAgKS5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy5kaXNhYmxlV29ya2luZ0xpbmtzKSk7XG5cbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIklnbm9yZSBvciBpbmNsdWRlIGZpbGVzIGluIHRoZSBnaXZlbiBkaXJlY3Rvcmllc1wiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJFbmFibGUgdG8gaWdub3JlIGZpbGVzIGluIHRoZSBnaXZlbiBkaXJlY3Rvcmllcy4gRGlzYWJsZSB0byBvbmx5IGluY2x1ZGUgZmlsZXMgaW4gdGhlIGdpdmVuIGRpcmVjdG9yaWVzXCIpXG4gICAgICAgICAgICAuYWRkVG9nZ2xlKGNiID0+XG4gICAgICAgICAgICAgICAgY2Iuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MuaWdub3JlRGlyZWN0b3JpZXMpXG4gICAgICAgICAgICAgICAgICAgIC5vbkNoYW5nZSh2YWx1ZSA9PiB7XG4gICAgICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy5pZ25vcmVEaXJlY3RvcmllcyA9IHZhbHVlO1xuICAgICAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgICAgIH0pKTtcblxuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiRGlyZWN0b3JpZXNcIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiQWRkIGVhY2ggZGlyZWN0b3J5IHBhdGggaW4gYSBuZXcgbGluZVwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwiRGlyZWN0b3J5L1N1YmRpcmVjdG9yeVwiKVxuICAgICAgICAgICAgICAgIC5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy5kaXJlY3Rvcmllc1RvSWdub3JlLmpvaW4oXCJcXG5cIikpXG4gICAgICAgICAgICAgICAgLm9uQ2hhbmdlKCh2YWx1ZSkgPT4ge1xuICAgICAgICAgICAgICAgICAgICBsZXQgcGF0aHMgPSB2YWx1ZS50cmltKCkuc3BsaXQoXCJcXG5cIikubWFwKHZhbHVlID0+IHRoaXMuZm9ybWF0UGF0aCh2YWx1ZSwgdHJ1ZSkpO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy5kaXJlY3Rvcmllc1RvSWdub3JlID0gcGF0aHM7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNhdmVTZXR0aW5ncygpO1xuICAgICAgICAgICAgICAgIH0pKTtcbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIkZpbGVzIHRvIGlnbm9yZS5cIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiQWRkIGVhY2ggZmlsZSBwYXRoIGluIGEgbmV3IGxpbmUgKHdpdGggZmlsZSBleHRlbnNpb24hKVwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwiRGlyZWN0b3J5L2ZpbGUubWRcIilcbiAgICAgICAgICAgICAgICAuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MuZmlsZXNUb0lnbm9yZS5qb2luKFwiXFxuXCIpKVxuICAgICAgICAgICAgICAgIC5vbkNoYW5nZSgodmFsdWUpID0+IHtcbiAgICAgICAgICAgICAgICAgICAgbGV0IHBhdGhzID0gdmFsdWUudHJpbSgpLnNwbGl0KFwiXFxuXCIpLm1hcCh2YWx1ZSA9PiB0aGlzLmZvcm1hdFBhdGgodmFsdWUsIGZhbHNlKSk7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLmZpbGVzVG9JZ25vcmUgPSBwYXRocztcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgfSkpO1xuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiTGlua3MgdG8gaWdub3JlLlwiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJJZ25vcmUgZmlsZXMsIHdoaWNoIGNvbnRhaW4gdGhlIGdpdmVuIGZpbGUgYXMgbGluay4gQWRkIGVhY2ggZmlsZSBwYXRoIGluIGEgbmV3IGxpbmUgKHdpdGggZmlsZSBleHRlbnNpb24hKS4gU2V0IGl0IHRvIGAqYCB0byBpZ25vcmUgZmlsZXMgd2l0aCBsaW5rcy5cIilcbiAgICAgICAgICAgIC5hZGRUZXh0QXJlYShjYiA9PiBjYlxuICAgICAgICAgICAgICAgIC5zZXRQbGFjZWhvbGRlcihcIkRpcmVjdG9yeS9maWxlLm1kXCIpXG4gICAgICAgICAgICAgICAgLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLmxpbmtzVG9JZ25vcmUuam9pbihcIlxcblwiKSlcbiAgICAgICAgICAgICAgICAub25DaGFuZ2UoKHZhbHVlKSA9PiB7XG4gICAgICAgICAgICAgICAgICAgIGxldCBwYXRocyA9IHZhbHVlLnRyaW0oKS5zcGxpdChcIlxcblwiKS5tYXAodmFsdWUgPT4gdGhpcy5mb3JtYXRQYXRoKHZhbHVlLCBmYWxzZSkpO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy5saW5rc1RvSWdub3JlID0gcGF0aHM7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNhdmVTZXR0aW5ncygpO1xuICAgICAgICAgICAgICAgIH0pKTtcbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIklnbm9yZSBvciBpbmNsdWRlIGZpbGVzIHdpdGggdGhlIGdpdmVuIGZpbGV0eXBlc1wiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJFbmFibGUgdG8gaWdub3JlIGZpbGVzIHdpdGggdGhlIGdpdmVuIGZpbGV0eXBlcy4gRGlzYWJsZSB0byBvbmx5IGluY2x1ZGUgZmlsZXMgd2l0aCB0aGUgZ2l2ZW4gZmlsZXR5cGVzXCIpXG4gICAgICAgICAgICAuYWRkVG9nZ2xlKGNiID0+XG4gICAgICAgICAgICAgICAgY2Iuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MuaWdub3JlRmlsZVR5cGVzKVxuICAgICAgICAgICAgICAgICAgICAub25DaGFuZ2UodmFsdWUgPT4ge1xuICAgICAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MuaWdub3JlRmlsZVR5cGVzID0gdmFsdWU7XG4gICAgICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgICAgICAgICAgfSkpO1xuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiRmlsZSB0eXBlc1wiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJFZmZlY3QgZGVwZW5kcyBvbiB0b2dnbGUgYWJvdmVcIilcbiAgICAgICAgICAgIC5hZGRUZXh0QXJlYShjYiA9PiBjYlxuICAgICAgICAgICAgICAgIC5zZXRQbGFjZWhvbGRlcihcImRvY3gsdHh0XCIpXG4gICAgICAgICAgICAgICAgLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLmZpbGVUeXBlc1RvSWdub3JlLmpvaW4oXCIsXCIpKVxuICAgICAgICAgICAgICAgIC5vbkNoYW5nZSgodmFsdWUpID0+IHtcbiAgICAgICAgICAgICAgICAgICAgbGV0IGV4dGVuc2lvbnMgPSB2YWx1ZS50cmltKCkuc3BsaXQoXCIsXCIpO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy5maWxlVHlwZXNUb0lnbm9yZSA9IGV4dGVuc2lvbnM7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNhdmVTZXR0aW5ncygpO1xuICAgICAgICAgICAgICAgIH0pKTtcbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIlRhZ3MgdG8gaWdub3JlLlwiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJJZ25vcmUgZmlsZXMsIHdoaWNoIGNvbnRhaW4gdGhlIGdpdmVuIHRhZy4gQWRkIGVhY2ggdGFnIHNlcGFyYXRlZCBieSBjb21tYSAod2l0aG91dCBgI2ApXCIpXG4gICAgICAgICAgICAuYWRkVGV4dEFyZWEoY2IgPT4gY2JcbiAgICAgICAgICAgICAgICAuc2V0UGxhY2Vob2xkZXIoXCJ0b2RvLHVuZmluaXNoZWRcIilcbiAgICAgICAgICAgICAgICAuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MudGFnc1RvSWdub3JlLmpvaW4oXCIsXCIpKVxuICAgICAgICAgICAgICAgIC5vbkNoYW5nZSgodmFsdWUpID0+IHtcbiAgICAgICAgICAgICAgICAgICAgbGV0IHRhZ3MgPSB2YWx1ZS50cmltKCkuc3BsaXQoXCIsXCIpO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy50YWdzVG9JZ25vcmUgPSB0YWdzO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgICAgICB9KSk7XG4gICAgICAgIG5ldyBTZXR0aW5nKGNvbnRhaW5lckVsKVxuICAgICAgICAgICAgLnNldE5hbWUoXCJGaWxldHlwZXMgdG8gZGVsZXRlIHBlciBjb21tYW5kLiBTZWUgUkVBRE1FLlwiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJBZGQgZWFjaCBmaWxldHlwZSBzZXBhcmF0ZWQgYnkgY29tbWEuIFNldCB0byBgKmAgdG8gZGVsZXRlIGFsbCBmaWxlcy5cIilcbiAgICAgICAgICAgIC5hZGRUZXh0QXJlYShjYiA9PiBjYlxuICAgICAgICAgICAgICAgIC5zZXRQbGFjZWhvbGRlcihcImpwZyxwbmdcIilcbiAgICAgICAgICAgICAgICAuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MuZmlsZVR5cGVzVG9EZWxldGUuam9pbihcIixcIikpXG4gICAgICAgICAgICAgICAgLm9uQ2hhbmdlKCh2YWx1ZSkgPT4ge1xuICAgICAgICAgICAgICAgICAgICBsZXQgZXh0ZW5zaW9ucyA9IHZhbHVlLnRyaW0oKS5zcGxpdChcIixcIik7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLmZpbGVUeXBlc1RvRGVsZXRlID0gZXh0ZW5zaW9ucztcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgfSkpO1xuXG5cbiAgICAgICAgLy8vIFNldHRpbmdzIGZvciBmaW5kIHVucmVzb2x2ZWRMaW5rc1xuICAgICAgICBjb250YWluZXJFbC5jcmVhdGVFbChcImg0XCIsIHsgdGV4dDogXCJTZXR0aW5ncyBmb3IgZmluZCB1bnJlc29sdmVkIGxpbmtzXCIgfSk7XG5cbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZSgnT3V0cHV0IGZpbGUgbmFtZScpXG4gICAgICAgICAgICAuc2V0RGVzYygnU2V0IG5hbWUgb2Ygb3V0cHV0IGZpbGUgKHdpdGhvdXQgZmlsZSBleHRlbnNpb24pLiBNYWtlIHN1cmUgbm8gZmlsZSBleGlzdHMgd2l0aCB0aGlzIG5hbWUgYmVjYXVzZSBpdCB3aWxsIGJlIG92ZXJ3cml0dGVuISBJZiB0aGUgbmFtZSBpcyBlbXB0eSwgdGhlIGRlZmF1bHQgbmFtZSBpcyBzZXQuJylcbiAgICAgICAgICAgIC5hZGRUZXh0KGNiID0+IGNiLm9uQ2hhbmdlKHZhbHVlID0+IHtcbiAgICAgICAgICAgICAgICBpZiAodmFsdWUubGVuZ3RoID09IDApIHtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzT3V0cHV0RmlsZU5hbWUgPSB0aGlzLmRlZmF1bHRTZXR0aW5ncy51bnJlc29sdmVkTGlua3NPdXRwdXRGaWxlTmFtZTtcbiAgICAgICAgICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NPdXRwdXRGaWxlTmFtZSA9IHZhbHVlO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgIH0pLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc091dHB1dEZpbGVOYW1lKSk7XG5cbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIkRpcmVjdG9yaWVzIHRvIGlnbm9yZS5cIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiSWdub3JlIGxpbmtzIGluIGZpbGVzIGluIHRoZSBzcGVjaWZpZWQgZGlyZWN0b3J5LiBBZGQgZWFjaCBkaXJlY3RvcnkgcGF0aCBpbiBhIG5ldyBsaW5lXCIpXG4gICAgICAgICAgICAuYWRkVGV4dEFyZWEoY2IgPT4gY2JcbiAgICAgICAgICAgICAgICAuc2V0UGxhY2Vob2xkZXIoXCJEaXJlY3RvcnkvU3ViZGlyZWN0b3J5XCIpXG4gICAgICAgICAgICAgICAgLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc0RpcmVjdG9yaWVzVG9JZ25vcmUuam9pbihcIlxcblwiKSlcbiAgICAgICAgICAgICAgICAub25DaGFuZ2UoKHZhbHVlKSA9PiB7XG4gICAgICAgICAgICAgICAgICAgIGxldCBwYXRocyA9IHZhbHVlLnRyaW0oKS5zcGxpdChcIlxcblwiKS5tYXAodmFsdWUgPT4gdGhpcy5mb3JtYXRQYXRoKHZhbHVlLCB0cnVlKSk7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc0RpcmVjdG9yaWVzVG9JZ25vcmUgPSBwYXRocztcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgfSkpO1xuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiRmlsZXMgdG8gaWdub3JlLlwiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJJZ25vcmUgbGlua3MgaW4gdGhlIHNwZWNpZmllZCBmaWxlLiBBZGQgZWFjaCBmaWxlIHBhdGggaW4gYSBuZXcgbGluZSAod2l0aCBmaWxlIGV4dGVuc2lvbiEpXCIpXG4gICAgICAgICAgICAuYWRkVGV4dEFyZWEoY2IgPT4gY2JcbiAgICAgICAgICAgICAgICAuc2V0UGxhY2Vob2xkZXIoXCJEaXJlY3RvcnkvZmlsZS5tZFwiKVxuICAgICAgICAgICAgICAgIC5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NGaWxlc1RvSWdub3JlLmpvaW4oXCJcXG5cIikpXG4gICAgICAgICAgICAgICAgLm9uQ2hhbmdlKCh2YWx1ZSkgPT4ge1xuICAgICAgICAgICAgICAgICAgICBsZXQgcGF0aHMgPSB2YWx1ZS50cmltKCkuc3BsaXQoXCJcXG5cIikubWFwKHZhbHVlID0+IHRoaXMuZm9ybWF0UGF0aCh2YWx1ZSwgZmFsc2UpKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzRmlsZXNUb0lnbm9yZSA9IHBhdGhzO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgICAgICB9KSk7XG4gICAgICAgIG5ldyBTZXR0aW5nKGNvbnRhaW5lckVsKVxuICAgICAgICAgICAgLnNldE5hbWUoXCJMaW5rcyB0byBpZ25vcmUuXCIpXG4gICAgICAgICAgICAuc2V0RGVzYyhcIklnbm9yZSBmaWxlcywgd2hpY2ggY29udGFpbiB0aGUgZ2l2ZW4gZmlsZSBhcyBsaW5rLiBBZGQgZWFjaCBmaWxlIHBhdGggaW4gYSBuZXcgbGluZSAod2l0aCBmaWxlIGV4dGVuc2lvbiEpLiBTZXQgaXQgdG8gYCpgIHRvIGlnbm9yZSBmaWxlcyB3aXRoIGxpbmtzLlwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwiRGlyZWN0b3J5L2ZpbGUubWRcIilcbiAgICAgICAgICAgICAgICAuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzTGlua3NUb0lnbm9yZS5qb2luKFwiXFxuXCIpKVxuICAgICAgICAgICAgICAgIC5vbkNoYW5nZSgodmFsdWUpID0+IHtcbiAgICAgICAgICAgICAgICAgICAgbGV0IHBhdGhzID0gdmFsdWUudHJpbSgpLnNwbGl0KFwiXFxuXCIpLm1hcCh2YWx1ZSA9PiB0aGlzLmZvcm1hdFBhdGgodmFsdWUsIGZhbHNlKSk7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc0xpbmtzVG9JZ25vcmUgPSBwYXRocztcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgfSkpO1xuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiRmlsZXR5cGVzIHRvIGlnbm9yZS5cIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiSWdub3JlIGxpbmtzIHdpdGggdGhlIHNwZWNpZmllZCBmaWxldHlwZS4gQWRkIGVhY2ggZmlsZXR5cGUgc2VwYXJhdGVkIGJ5IGNvbW1hXCIpXG4gICAgICAgICAgICAuYWRkVGV4dEFyZWEoY2IgPT4gY2JcbiAgICAgICAgICAgICAgICAuc2V0UGxhY2Vob2xkZXIoXCJkb2N4LHR4dFwiKVxuICAgICAgICAgICAgICAgIC5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NGaWxlVHlwZXNUb0lnbm9yZS5qb2luKFwiLFwiKSlcbiAgICAgICAgICAgICAgICAub25DaGFuZ2UoKHZhbHVlKSA9PiB7XG4gICAgICAgICAgICAgICAgICAgIGxldCBleHRlbnNpb25zID0gdmFsdWUudHJpbSgpLnNwbGl0KFwiLFwiKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzRmlsZVR5cGVzVG9JZ25vcmUgPSBleHRlbnNpb25zO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgICAgICB9KSk7XG4gICAgICAgIG5ldyBTZXR0aW5nKGNvbnRhaW5lckVsKVxuICAgICAgICAgICAgLnNldE5hbWUoXCJUYWdzIHRvIGlnbm9yZS5cIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiSWdub3JlIGxpbmtzIGluIGZpbGVzLCB3aGljaCBjb250YWluIHRoZSBnaXZlbiB0YWcuIEFkZCBlYWNoIHRhZyBzZXBhcmF0ZWQgYnkgY29tbWEgKHdpdGhvdXQgYCNgKVwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwidG9kbyx1bmZpbmlzaGVkXCIpXG4gICAgICAgICAgICAgICAgLnNldFZhbHVlKHRoaXMucGx1Z2luLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc1RhZ3NUb0lnbm9yZS5qb2luKFwiLFwiKSlcbiAgICAgICAgICAgICAgICAub25DaGFuZ2UoKHZhbHVlKSA9PiB7XG4gICAgICAgICAgICAgICAgICAgIGxldCB0YWdzID0gdmFsdWUudHJpbSgpLnNwbGl0KFwiLFwiKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzVGFnc1RvSWdub3JlID0gdGFncztcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICAgICAgfSkpO1xuXG4gICAgICAgIGNvbnRhaW5lckVsLmNyZWF0ZUVsKFwiaDRcIiwgeyB0ZXh0OiBcIlNldHRpbmdzIGZvciBmaW5kIGZpbGVzIHdpdGhvdXQgdGFnc1wiIH0pO1xuXG4gICAgICAgIG5ldyBTZXR0aW5nKGNvbnRhaW5lckVsKVxuICAgICAgICAgICAgLnNldE5hbWUoJ091dHB1dCBmaWxlIG5hbWUnKVxuICAgICAgICAgICAgLnNldERlc2MoJ1NldCBuYW1lIG9mIG91dHB1dCBmaWxlICh3aXRob3V0IGZpbGUgZXh0ZW5zaW9uKS4gTWFrZSBzdXJlIG5vIGZpbGUgZXhpc3RzIHdpdGggdGhpcyBuYW1lIGJlY2F1c2UgaXQgd2lsbCBiZSBvdmVyd3JpdHRlbiEgSWYgdGhlIG5hbWUgaXMgZW1wdHksIHRoZSBkZWZhdWx0IG5hbWUgaXMgc2V0LicpXG4gICAgICAgICAgICAuYWRkVGV4dChjYiA9PiBjYi5vbkNoYW5nZSh2YWx1ZSA9PiB7XG4gICAgICAgICAgICAgICAgaWYgKHZhbHVlLmxlbmd0aCA9PSAwKSB7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLndpdGhvdXRUYWdzT3V0cHV0RmlsZU5hbWUgPSB0aGlzLmRlZmF1bHRTZXR0aW5ncy53aXRob3V0VGFnc091dHB1dEZpbGVOYW1lO1xuICAgICAgICAgICAgICAgIH0gZWxzZSB7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLndpdGhvdXRUYWdzT3V0cHV0RmlsZU5hbWUgPSB2YWx1ZTtcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2F2ZVNldHRpbmdzKCk7XG4gICAgICAgICAgICB9KS5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy53aXRob3V0VGFnc091dHB1dEZpbGVOYW1lKSk7XG5cbiAgICAgICAgbmV3IFNldHRpbmcoY29udGFpbmVyRWwpXG4gICAgICAgICAgICAuc2V0TmFtZShcIkZpbGVzIHRvIGlnbm9yZS5cIilcbiAgICAgICAgICAgIC5zZXREZXNjKFwiSWdub3JlIHRoZSBzcGVjaWZpYyBmaWxlcy4gQWRkIGVhY2ggZmlsZSBwYXRoIGluIGEgbmV3IGxpbmUgKHdpdGggZmlsZSBleHRlbnNpb24hKVwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwiRGlyZWN0b3J5L2ZpbGUubWRcIilcbiAgICAgICAgICAgICAgICAuc2V0VmFsdWUodGhpcy5wbHVnaW4uc2V0dGluZ3Mud2l0aG91dFRhZ3NGaWxlc1RvSWdub3JlLmpvaW4oXCJcXG5cIikpXG4gICAgICAgICAgICAgICAgLm9uQ2hhbmdlKCh2YWx1ZSkgPT4ge1xuICAgICAgICAgICAgICAgICAgICBsZXQgcGF0aHMgPSB2YWx1ZS50cmltKCkuc3BsaXQoXCJcXG5cIikubWFwKHZhbHVlID0+IHRoaXMuZm9ybWF0UGF0aCh2YWx1ZSwgZmFsc2UpKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy5wbHVnaW4uc2V0dGluZ3Mud2l0aG91dFRhZ3NGaWxlc1RvSWdub3JlID0gcGF0aHM7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNhdmVTZXR0aW5ncygpO1xuICAgICAgICAgICAgICAgIH0pKTtcblxuICAgICAgICBuZXcgU2V0dGluZyhjb250YWluZXJFbClcbiAgICAgICAgICAgIC5zZXROYW1lKFwiRGlyZWN0b3JpZXMgdG8gaWdub3JlLlwiKVxuICAgICAgICAgICAgLnNldERlc2MoXCJJZ25vcmUgZmlsZXMgaW4gdGhlIHNwZWNpZmllZCBkaXJlY3Rvcmllcy4gQWRkIGVhY2ggZGlyZWN0b3J5IHBhdGggaW4gYSBuZXcgbGluZVwiKVxuICAgICAgICAgICAgLmFkZFRleHRBcmVhKGNiID0+IGNiXG4gICAgICAgICAgICAgICAgLnNldFBsYWNlaG9sZGVyKFwiRGlyZWN0b3J5L1N1YmRpcmVjdG9yeVwiKVxuICAgICAgICAgICAgICAgIC5zZXRWYWx1ZSh0aGlzLnBsdWdpbi5zZXR0aW5ncy53aXRob3V0VGFnc0RpcmVjdG9yaWVzVG9JZ25vcmUuam9pbihcIlxcblwiKSlcbiAgICAgICAgICAgICAgICAub25DaGFuZ2UoKHZhbHVlKSA9PiB7XG4gICAgICAgICAgICAgICAgICAgIGxldCBwYXRocyA9IHZhbHVlLnRyaW0oKS5zcGxpdChcIlxcblwiKS5tYXAodmFsdWUgPT4gdGhpcy5mb3JtYXRQYXRoKHZhbHVlLCB0cnVlKSk7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMucGx1Z2luLnNldHRpbmdzLndpdGhvdXRUYWdzRGlyZWN0b3JpZXNUb0lnbm9yZSA9IHBhdGhzO1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnBsdWdpbi5zYXZlU2V0dGluZ3MoKTtcbiAgICAgICAgICAgICAgICB9KSk7XG4gICAgfVxufVxuIiwiaW1wb3J0IHsgQXBwLCBDYWNoZWRNZXRhZGF0YSwgZ2V0QWxsVGFncywgaXRlcmF0ZUNhY2hlUmVmcyB9IGZyb20gXCJvYnNpZGlhblwiO1xuXG5leHBvcnQgY2xhc3MgVXRpbHMge1xuICAgIHByaXZhdGUgZmlsZUNhY2hlOiBDYWNoZWRNZXRhZGF0YTtcblxuICAgIC8qKlxuICAgICAqIENoZWNrcyBmb3IgdGhlIGdpdmVuIHNldHRpbmdzLiBJcyB1c2VkIGZvciBgRmluZCB1bmxpbmtlZCBmaWxlc2AgYW5kIGBGaW5kIHVucmVzb2x2ZWQgbGlua3NgXG4gICAgICogQHBhcmFtIGFwcCBcbiAgICAgKiBAcGFyYW0gZmlsZVBhdGggXG4gICAgICogQHBhcmFtIHRhZ3NUb0lnbm9yZSBcbiAgICAgKiBAcGFyYW0gbGlua3NUb0lnbm9yZSBcbiAgICAgKiBAcGFyYW0gZGlyZWN0b3JpZXNUb0lnbm9yZSBcbiAgICAgKiBAcGFyYW0gZmlsZXNUb0lnbm9yZSBcbiAgICAgKiBAcGFyYW0gaWdub3JlRGlyZWN0b3JpZXNcbiAgICAgKi9cbiAgICBjb25zdHJ1Y3RvcihcbiAgICAgICAgcHJpdmF0ZSBhcHA6IEFwcCxcbiAgICAgICAgcHJpdmF0ZSBmaWxlUGF0aDogc3RyaW5nLFxuICAgICAgICBwcml2YXRlIHRhZ3NUb0lnbm9yZTogc3RyaW5nW10sXG4gICAgICAgIHByaXZhdGUgbGlua3NUb0lnbm9yZTogc3RyaW5nW10sXG4gICAgICAgIHByaXZhdGUgZGlyZWN0b3JpZXNUb0lnbm9yZTogc3RyaW5nW10sXG4gICAgICAgIHByaXZhdGUgZmlsZXNUb0lnbm9yZTogc3RyaW5nW10sXG4gICAgICAgIHByaXZhdGUgaWdub3JlRGlyZWN0b3JpZXM6IGJvb2xlYW4gPSB0cnVlLFxuICAgICkge1xuICAgICAgICB0aGlzLmZpbGVDYWNoZSA9IGFwcC5tZXRhZGF0YUNhY2hlLmdldENhY2hlKGZpbGVQYXRoKTtcbiAgICB9XG5cbiAgICBwcml2YXRlIGhhc1RhZ3NUb0lnbm9yZSgpOiBib29sZWFuIHtcbiAgICAgICAgY29uc3QgdGFncyA9IGdldEFsbFRhZ3ModGhpcy5maWxlQ2FjaGUpO1xuICAgICAgICByZXR1cm4gdGFncz8uZmluZCgodGFnKSA9PiB0aGlzLnRhZ3NUb0lnbm9yZS5jb250YWlucyh0YWcuc3Vic3RyaW5nKDEpKSkgIT09IHVuZGVmaW5lZDtcbiAgICB9XG4gICAgcHJpdmF0ZSBoYXNMaW5rc1RvSWdub3JlKCk6IGJvb2xlYW4ge1xuICAgICAgICBpZiAoKHRoaXMuZmlsZUNhY2hlPy5lbWJlZHMgIT0gbnVsbCB8fCB0aGlzLmZpbGVDYWNoZT8ubGlua3MgIT0gbnVsbCkgJiYgdGhpcy5saW5rc1RvSWdub3JlWzBdID09IFwiKlwiKSB7XG4gICAgICAgICAgICByZXR1cm4gdHJ1ZTtcbiAgICAgICAgfVxuXG4gICAgICAgIHJldHVybiBpdGVyYXRlQ2FjaGVSZWZzKHRoaXMuZmlsZUNhY2hlLCBjYiA9PiB7XG4gICAgICAgICAgICBjb25zdCBsaW5rID0gdGhpcy5hcHAubWV0YWRhdGFDYWNoZS5nZXRGaXJzdExpbmtwYXRoRGVzdChjYi5saW5rLCB0aGlzLmZpbGVQYXRoKT8ucGF0aDtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLmxpbmtzVG9JZ25vcmUuY29udGFpbnMobGluayk7XG4gICAgICAgIH0pO1xuICAgIH1cblxuICAgIHByaXZhdGUgY2hlY2tEaXJlY3RvcnkoKTogYm9vbGVhbiB7XG4gICAgICAgIGNvbnN0IGNvbnRhaW5zID0gdGhpcy5kaXJlY3Rvcmllc1RvSWdub3JlLmZpbmQoKHZhbHVlKSA9PiB0aGlzLmZpbGVQYXRoLnN0YXJ0c1dpdGgodmFsdWUpICYmIHZhbHVlLmxlbmd0aCAhPSAwKSAhPT0gdW5kZWZpbmVkO1xuICAgICAgICBpZiAodGhpcy5pZ25vcmVEaXJlY3Rvcmllcykge1xuICAgICAgICAgICAgcmV0dXJuIGNvbnRhaW5zO1xuICAgICAgICB9IGVsc2Uge1xuICAgICAgICAgICAgcmV0dXJuICFjb250YWlucztcbiAgICAgICAgfVxuICAgIH1cblxuICAgIHByaXZhdGUgaXNGaWxlVG9JZ25vcmUoKSB7XG4gICAgICAgIHJldHVybiB0aGlzLmZpbGVzVG9JZ25vcmUuY29udGFpbnModGhpcy5maWxlUGF0aCk7XG4gICAgfVxuXG4gICAgcHVibGljIGlzVmFsaWQoKSB7XG4gICAgICAgIHJldHVybiAhdGhpcy5oYXNUYWdzVG9JZ25vcmUoKSAmJiAhdGhpcy5oYXNMaW5rc1RvSWdub3JlKCkgJiYgIXRoaXMuY2hlY2tEaXJlY3RvcnkoKSAmJiAhdGhpcy5pc0ZpbGVUb0lnbm9yZSgpO1xuICAgIH1cblxuICAgIC8qKlxuICAgICAqIFdyaXRlcyB0aGUgdGV4dCB0byB0aGUgZmlsZSBhbmQgb3BlbnMgdGhlIGZpbGUgaW4gYSBuZXcgcGFuZSBpZiBpdCBpcyBub3Qgb3BlbmVkIHlldFxuICAgICAqIEBwYXJhbSBhcHAgXG4gICAgICogQHBhcmFtIG91dHB1dEZpbGVOYW1lIG5hbWUgb2YgdGhlIG91dHB1dCBmaWxlXG4gICAgICogQHBhcmFtIHRleHQgZGF0YSB0byBiZSB3cml0dGVuIHRvIHRoZSBmaWxlXG4gICAgICovXG4gICAgc3RhdGljIGFzeW5jIHdyaXRlQW5kT3BlbkZpbGUoYXBwOiBBcHAsIG91dHB1dEZpbGVOYW1lOiBzdHJpbmcsIHRleHQ6IHN0cmluZykge1xuICAgICAgICBhd2FpdCBhcHAudmF1bHQuYWRhcHRlci53cml0ZShvdXRwdXRGaWxlTmFtZSwgdGV4dCk7XG5cbiAgICAgICAgbGV0IGZpbGVJc0FscmVhZHlPcGVuZWQgPSBmYWxzZTtcbiAgICAgICAgYXBwLndvcmtzcGFjZS5pdGVyYXRlQWxsTGVhdmVzKGxlYWYgPT4ge1xuICAgICAgICAgICAgaWYgKGxlYWYuZ2V0RGlzcGxheVRleHQoKSAhPSBcIlwiICYmIG91dHB1dEZpbGVOYW1lLnN0YXJ0c1dpdGgobGVhZi5nZXREaXNwbGF5VGV4dCgpKSkge1xuICAgICAgICAgICAgICAgIGZpbGVJc0FscmVhZHlPcGVuZWQgPSB0cnVlO1xuICAgICAgICAgICAgfVxuICAgICAgICB9KTtcbiAgICAgICAgaWYgKCFmaWxlSXNBbHJlYWR5T3BlbmVkKVxuICAgICAgICAgICAgYXBwLndvcmtzcGFjZS5vcGVuTGlua1RleHQob3V0cHV0RmlsZU5hbWUsIFwiL1wiLCB0cnVlKTtcbiAgICB9XG59IiwiaW1wb3J0IHsgZ2V0QWxsVGFncywgZ2V0TGlua3BhdGgsIGl0ZXJhdGVDYWNoZVJlZnMsIE5vdGljZSwgUGx1Z2luLCBURmlsZSB9IGZyb20gJ29ic2lkaWFuJztcclxuaW1wb3J0IHsgRGVsZXRlRmlsZXNNb2RhbCB9IGZyb20gJy4vZGVsZXRlRmlsZXNNb2RhbCc7XHJcbmltcG9ydCB7IFNldHRpbmdzVGFiIH0gZnJvbSAnLi9zZXR0aW5nc1RhYic7XHJcbmltcG9ydCB7IFV0aWxzIH0gZnJvbSAnLi91dGlscyc7XHJcblxyXG5leHBvcnQgaW50ZXJmYWNlIFNldHRpbmdzIHtcclxuXHRvdXRwdXRGaWxlTmFtZTogc3RyaW5nO1xyXG5cdGRpc2FibGVXb3JraW5nTGlua3M6IGJvb2xlYW47XHJcblx0ZGlyZWN0b3JpZXNUb0lnbm9yZTogc3RyaW5nW107XHJcblx0ZmlsZXNUb0lnbm9yZTogc3RyaW5nW107XHJcblx0ZmlsZVR5cGVzVG9JZ25vcmU6IHN0cmluZ1tdO1xyXG5cdGxpbmtzVG9JZ25vcmU6IHN0cmluZ1tdO1xyXG5cdHRhZ3NUb0lnbm9yZTogc3RyaW5nW107XHJcblx0ZmlsZVR5cGVzVG9EZWxldGU6IHN0cmluZ1tdO1xyXG5cdGlnbm9yZUZpbGVUeXBlczogYm9vbGVhbjtcclxuXHRpZ25vcmVEaXJlY3RvcmllczogYm9vbGVhbjtcclxuXHR1bnJlc29sdmVkTGlua3NEaXJlY3Rvcmllc1RvSWdub3JlOiBzdHJpbmdbXTtcclxuXHR1bnJlc29sdmVkTGlua3NGaWxlc1RvSWdub3JlOiBzdHJpbmdbXTtcclxuXHR1bnJlc29sdmVkTGlua3NGaWxlVHlwZXNUb0lnbm9yZTogc3RyaW5nW107XHJcblx0dW5yZXNvbHZlZExpbmtzTGlua3NUb0lnbm9yZTogc3RyaW5nW107XHJcblx0dW5yZXNvbHZlZExpbmtzVGFnc1RvSWdub3JlOiBzdHJpbmdbXTtcclxuXHR1bnJlc29sdmVkTGlua3NPdXRwdXRGaWxlTmFtZTogc3RyaW5nO1xyXG5cdHdpdGhvdXRUYWdzRGlyZWN0b3JpZXNUb0lnbm9yZTogc3RyaW5nW107XHJcblx0d2l0aG91dFRhZ3NGaWxlc1RvSWdub3JlOiBzdHJpbmdbXTtcclxuXHR3aXRob3V0VGFnc091dHB1dEZpbGVOYW1lOiBzdHJpbmc7XHJcbn1cclxuY29uc3QgREVGQVVMVF9TRVRUSU5HUzogU2V0dGluZ3MgPSB7XHJcblx0b3V0cHV0RmlsZU5hbWU6IFwidW5saW5rZWQgZmlsZXMgb3V0cHV0XCIsXHJcblx0ZGlzYWJsZVdvcmtpbmdMaW5rczogZmFsc2UsXHJcblx0ZGlyZWN0b3JpZXNUb0lnbm9yZTogW10sXHJcblx0ZmlsZXNUb0lnbm9yZTogW10sXHJcblx0ZmlsZVR5cGVzVG9JZ25vcmU6IFtdLFxyXG5cdGxpbmtzVG9JZ25vcmU6IFtdLFxyXG5cdHRhZ3NUb0lnbm9yZTogW10sXHJcblx0ZmlsZVR5cGVzVG9EZWxldGU6IFtdLFxyXG5cdGlnbm9yZUZpbGVUeXBlczogdHJ1ZSxcclxuXHRpZ25vcmVEaXJlY3RvcmllczogdHJ1ZSxcclxuXHR1bnJlc29sdmVkTGlua3NPdXRwdXRGaWxlTmFtZTogXCJ1bnJlc29sdmVkIGxpbmtzIG91dHB1dFwiLFxyXG5cdHVucmVzb2x2ZWRMaW5rc0RpcmVjdG9yaWVzVG9JZ25vcmU6IFtdLFxyXG5cdHVucmVzb2x2ZWRMaW5rc0ZpbGVzVG9JZ25vcmU6IFtdLFxyXG5cdHVucmVzb2x2ZWRMaW5rc0ZpbGVUeXBlc1RvSWdub3JlOiBbXSxcclxuXHR1bnJlc29sdmVkTGlua3NMaW5rc1RvSWdub3JlOiBbXSxcclxuXHR1bnJlc29sdmVkTGlua3NUYWdzVG9JZ25vcmU6IFtdLFxyXG5cdHdpdGhvdXRUYWdzRGlyZWN0b3JpZXNUb0lnbm9yZTogW10sXHJcblx0d2l0aG91dFRhZ3NGaWxlc1RvSWdub3JlOiBbXSxcclxuXHR3aXRob3V0VGFnc091dHB1dEZpbGVOYW1lOiBcImZpbGVzIHdpdGhvdXQgdGFnc1wiXHJcbn07XHJcbmludGVyZmFjZSBVbnJlc29sdmVkTGluayB7XHJcblx0bGluazogc3RyaW5nO1xyXG5cdGZpbGVzOiBzdHJpbmdbXTtcclxufVxyXG5leHBvcnQgZGVmYXVsdCBjbGFzcyBGaW5kVW5saW5rZWRGaWxlc1BsdWdpbiBleHRlbmRzIFBsdWdpbiB7XHJcblx0c2V0dGluZ3M6IFNldHRpbmdzO1xyXG5cdGFzeW5jIG9ubG9hZCgpIHtcclxuXHRcdGNvbnNvbGUubG9nKCdsb2FkaW5nICcgKyB0aGlzLm1hbmlmZXN0Lm5hbWUgKyBcIiBwbHVnaW5cIik7XHJcblx0XHRhd2FpdCB0aGlzLmxvYWRTZXR0aW5ncygpO1xyXG5cdFx0dGhpcy5hZGRDb21tYW5kKHtcclxuXHRcdFx0aWQ6ICdmaW5kLXVubGlua2VkLWZpbGVzJyxcclxuXHRcdFx0bmFtZTogJ0ZpbmQgdW5saW5rZWQgZmlsZXMnLFxyXG5cdFx0XHRjYWxsYmFjazogKCkgPT4gdGhpcy5maW5kVW5saW5rZWRGaWxlcygpLFxyXG5cdFx0fSk7XHJcblx0XHR0aGlzLmFkZENvbW1hbmQoe1xyXG5cdFx0XHRpZDogJ2ZpbmQtdW5yZXNvbHZlZC1saW5rJyxcclxuXHRcdFx0bmFtZTogJ0ZpbmQgdW5yZXNvbHZlZCBsaW5rcycsXHJcblx0XHRcdGNhbGxiYWNrOiAoKSA9PiB0aGlzLmZpbmRVbnJlc29sdmVkTGlua3MoKSxcclxuXHRcdH0pO1xyXG5cdFx0dGhpcy5hZGRDb21tYW5kKHtcclxuXHRcdFx0aWQ6IFwiZGVsZXRlLXVubGlua2VkLWZpbGVzXCIsXHJcblx0XHRcdG5hbWU6IFwiRGVsZXRlIHVubGlua2VkIGZpbGVzIHdpdGggY2VydGFpbiBleHRlbnNpb24uIFNlZSBSRUFETUVcIixcclxuXHRcdFx0Y2FsbGJhY2s6ICgpID0+IHRoaXMuZGVsZXRlVW5saW5rZWRGaWxlcygpXHJcblx0XHR9KTtcclxuXHRcdHRoaXMuYWRkQ29tbWFuZCh7XHJcblx0XHRcdGlkOiBcImZpbmQtZmlsZXMtd2l0aG91dC10YWdzXCIsXHJcblx0XHRcdG5hbWU6IFwiRmluZCBmaWxlcyB3aXRob3V0IHRhZ3NcIixcclxuXHRcdFx0Y2FsbGJhY2s6ICgpID0+IHRoaXMuZmluZEZpbGVzV2l0aG91dFRhZ3MoKVxyXG5cdFx0fSk7XHJcblx0XHR0aGlzLmFkZFNldHRpbmdUYWIobmV3IFNldHRpbmdzVGFiKHRoaXMuYXBwLCB0aGlzLCBERUZBVUxUX1NFVFRJTkdTKSk7XHJcblx0fVxyXG5cdGZpbmRVbmxpbmtlZEZpbGVzKCkge1xyXG5cdFx0Y29uc3Qgb3V0RmlsZU5hbWUgPSB0aGlzLnNldHRpbmdzLm91dHB1dEZpbGVOYW1lICsgXCIubWRcIjtcclxuXHRcdGxldCBvdXRGaWxlOiBURmlsZTtcclxuXHRcdGNvbnN0IGZpbGVzID0gdGhpcy5hcHAudmF1bHQuZ2V0RmlsZXMoKTtcclxuXHRcdGNvbnN0IG1hcmtkb3duRmlsZXMgPSB0aGlzLmFwcC52YXVsdC5nZXRNYXJrZG93bkZpbGVzKCk7XHJcblx0XHRsZXQgbGlua3M6IHN0cmluZ1tdID0gW107XHJcblxyXG5cdFx0bWFya2Rvd25GaWxlcy5mb3JFYWNoKChtYXJrRmlsZTogVEZpbGUpID0+IHtcclxuXHRcdFx0aWYgKG1hcmtGaWxlLnBhdGggPT0gb3V0RmlsZU5hbWUpIHtcclxuXHRcdFx0XHRvdXRGaWxlID0gbWFya0ZpbGU7XHJcblx0XHRcdFx0cmV0dXJuO1xyXG5cdFx0XHR9XHJcblx0XHRcdGl0ZXJhdGVDYWNoZVJlZnModGhpcy5hcHAubWV0YWRhdGFDYWNoZS5nZXRGaWxlQ2FjaGUobWFya0ZpbGUpLCBjYiA9PiB7XHJcblx0XHRcdFx0bGV0IHR4dCA9IHRoaXMuYXBwLm1ldGFkYXRhQ2FjaGUuZ2V0Rmlyc3RMaW5rcGF0aERlc3QoZ2V0TGlua3BhdGgoY2IubGluayksIG1hcmtGaWxlLnBhdGgpO1xyXG5cdFx0XHRcdGlmICh0eHQgIT0gbnVsbClcclxuXHRcdFx0XHRcdGxpbmtzLnB1c2godHh0LnBhdGgpO1xyXG5cdFx0XHR9KTtcclxuXHRcdH0pO1xyXG5cdFx0Y29uc3Qgbm90TGlua2VkRmlsZXMgPSBmaWxlcy5maWx0ZXIoKGZpbGUpID0+IHRoaXMuaXNWYWxpZChmaWxlLCBsaW5rcykpO1xyXG5cdFx0bm90TGlua2VkRmlsZXMucmVtb3ZlKG91dEZpbGUpO1xyXG5cclxuXHJcblx0XHRsZXQgdGV4dCA9IFwiXCI7XHJcblx0XHRsZXQgcHJlZml4OiBzdHJpbmc7XHJcblx0XHRpZiAodGhpcy5zZXR0aW5ncy5kaXNhYmxlV29ya2luZ0xpbmtzKVxyXG5cdFx0XHRwcmVmaXggPSBcIlx0XCI7XHJcblx0XHRlbHNlXHJcblx0XHRcdHByZWZpeCA9IFwiXCI7XHJcblx0XHRub3RMaW5rZWRGaWxlcy5mb3JFYWNoKChmaWxlKSA9PiB7XHJcblx0XHRcdHRleHQgKz0gcHJlZml4ICsgXCItIFtbXCIgKyB0aGlzLmFwcC5tZXRhZGF0YUNhY2hlLmZpbGVUb0xpbmt0ZXh0KGZpbGUsIFwiL1wiKSArIFwiXV1cXG5cIjtcclxuXHRcdH0pO1xyXG5cdFx0VXRpbHMud3JpdGVBbmRPcGVuRmlsZSh0aGlzLmFwcCwgb3V0RmlsZU5hbWUsIHRleHQpO1xyXG5cclxuXHR9XHJcblx0YXN5bmMgZGVsZXRlVW5saW5rZWRGaWxlcygpIHtcclxuXHRcdGlmICghYXdhaXQgdGhpcy5hcHAudmF1bHQuYWRhcHRlci5leGlzdHModGhpcy5zZXR0aW5ncy5vdXRwdXRGaWxlTmFtZSArIFwiLm1kXCIpKSB7XHJcblx0XHRcdG5ldyBOb3RpY2UoXCJDYW4ndCBmaW5kIGZpbGUgLSBQbGVhc2UgcnVuIHRoZSBgRmluZCB1bmxpbmtlZCBmaWxlcycgY29tbWFuZCBiZWZvcmVcIik7XHJcblx0XHRcdHJldHVybjtcclxuXHRcdH1cclxuXHRcdGNvbnN0IGxpbmtzID0gdGhpcy5hcHAubWV0YWRhdGFDYWNoZS5nZXRDYWNoZSh0aGlzLnNldHRpbmdzLm91dHB1dEZpbGVOYW1lICsgXCIubWRcIik/LmxpbmtzID8/IFtdO1xyXG5cdFx0Y29uc3QgZmlsZXNUb0RlbGV0ZTogVEZpbGVbXSA9IFtdO1xyXG5cdFx0Y29uc29sZS5sb2codGhpcy5zZXR0aW5ncy5maWxlVHlwZXNUb0RlbGV0ZSk7XHJcblx0XHRsaW5rcy5mb3JFYWNoKChsaW5rKSA9PiB7XHJcblx0XHRcdGNvbnN0IGZpbGUgPSB0aGlzLmFwcC5tZXRhZGF0YUNhY2hlLmdldEZpcnN0TGlua3BhdGhEZXN0KGxpbmsubGluaywgXCIvXCIpO1xyXG5cdFx0XHRpZiAoIWZpbGUpXHJcblx0XHRcdFx0cmV0dXJuO1xyXG5cclxuXHRcdFx0aWYgKHRoaXMuc2V0dGluZ3MuZmlsZVR5cGVzVG9EZWxldGVbMF0gPT0gXCIqXCIgfHwgdGhpcy5zZXR0aW5ncy5maWxlVHlwZXNUb0RlbGV0ZS5jb250YWlucyhmaWxlLmV4dGVuc2lvbikpIHtcclxuXHRcdFx0XHRmaWxlc1RvRGVsZXRlLnB1c2goZmlsZSk7XHJcblx0XHRcdH1cclxuXHRcdH0pO1xyXG5cdFx0aWYgKGZpbGVzVG9EZWxldGUubGVuZ3RoID4gMClcclxuXHRcdFx0bmV3IERlbGV0ZUZpbGVzTW9kYWwodGhpcy5hcHAsIGZpbGVzVG9EZWxldGUpLm9wZW4oKTtcclxuXHR9XHJcblx0ZmluZFVucmVzb2x2ZWRMaW5rcygpIHtcclxuXHRcdGNvbnN0IG91dEZpbGVOYW1lID0gdGhpcy5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NPdXRwdXRGaWxlTmFtZSArIFwiLm1kXCI7XHJcblx0XHRjb25zdCBsaW5rczogVW5yZXNvbHZlZExpbmtbXSA9IFtdO1xyXG5cdFx0Y29uc3QgdW5yZXNvbHZlZExpbmtzID0gdGhpcy5hcHAubWV0YWRhdGFDYWNoZS51bnJlc29sdmVkTGlua3M7XHJcblxyXG5cdFx0Zm9yIChsZXQgZmlsZVBhdGggaW4gdW5yZXNvbHZlZExpbmtzKSB7XHJcblx0XHRcdGlmIChmaWxlUGF0aCA9PSB0aGlzLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc091dHB1dEZpbGVOYW1lICsgXCIubWRcIikgY29udGludWU7XHJcblxyXG5cdFx0XHRjb25zdCBmaWxlVHlwZSA9IGZpbGVQYXRoLnN1YnN0cmluZyhmaWxlUGF0aC5sYXN0SW5kZXhPZihcIi5cIikgKyAxKTtcclxuXHJcblx0XHRcdGNvbnN0IHV0aWxzID0gbmV3IFV0aWxzKFxyXG5cdFx0XHRcdHRoaXMuYXBwLFxyXG5cdFx0XHRcdGZpbGVQYXRoLFxyXG5cdFx0XHRcdHRoaXMuc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzVGFnc1RvSWdub3JlLFxyXG5cdFx0XHRcdHRoaXMuc2V0dGluZ3MudW5yZXNvbHZlZExpbmtzTGlua3NUb0lnbm9yZSxcclxuXHRcdFx0XHR0aGlzLnNldHRpbmdzLnVucmVzb2x2ZWRMaW5rc0RpcmVjdG9yaWVzVG9JZ25vcmUsXHJcblx0XHRcdFx0dGhpcy5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NGaWxlc1RvSWdub3JlXHJcblx0XHRcdCk7XHJcblx0XHRcdGlmICghdXRpbHMuaXNWYWxpZCgpKSBjb250aW51ZTtcclxuXHJcblx0XHRcdGZvciAoY29uc3QgbGluayBpbiB1bnJlc29sdmVkTGlua3NbZmlsZVBhdGhdKSB7XHJcblx0XHRcdFx0Y29uc3QgbGlua0ZpbGVUeXBlID0gbGluay5zdWJzdHJpbmcobGluay5sYXN0SW5kZXhPZihcIi5cIikgKyAxKTtcclxuXHRcdFx0XHRjb25zb2xlLmxvZyhsaW5rRmlsZVR5cGUpO1xyXG5cclxuXHRcdFx0XHRpZiAodGhpcy5zZXR0aW5ncy51bnJlc29sdmVkTGlua3NGaWxlVHlwZXNUb0lnbm9yZS5jb250YWlucyhsaW5rRmlsZVR5cGUpKSBjb250aW51ZTtcclxuXHJcblx0XHRcdFx0bGV0IGZvcm1hdHRlZEZpbGVQYXRoID0gZmlsZVBhdGg7XHJcblx0XHRcdFx0aWYgKGZpbGVUeXBlID09IFwibWRcIikge1xyXG5cdFx0XHRcdFx0Zm9ybWF0dGVkRmlsZVBhdGggPSBmaWxlUGF0aC5zdWJzdHJpbmcoMCwgZmlsZVBhdGgubGFzdEluZGV4T2YoXCIubWRcIikpO1xyXG5cdFx0XHRcdH1cclxuXHRcdFx0XHRjb25zdCB1bnJlc29sdmVkTGluazogVW5yZXNvbHZlZExpbmsgPSB7IGZpbGVzOiBbZm9ybWF0dGVkRmlsZVBhdGhdLCBsaW5rOiBsaW5rIH07XHJcblx0XHRcdFx0aWYgKGxpbmtzLmNvbnRhaW5zKHVucmVzb2x2ZWRMaW5rKSlcclxuXHRcdFx0XHRcdGNvbnRpbnVlO1xyXG5cdFx0XHRcdGNvbnN0IGR1cGxpY2F0aW9uID0gbGlua3MuZmluZCgoZSkgPT4gZS5saW5rID09IGxpbmspO1xyXG5cdFx0XHRcdGlmIChkdXBsaWNhdGlvbikge1xyXG5cdFx0XHRcdFx0ZHVwbGljYXRpb24uZmlsZXMucHVzaChmb3JtYXR0ZWRGaWxlUGF0aCk7XHJcblx0XHRcdFx0fSBlbHNlIHtcclxuXHRcdFx0XHRcdGxpbmtzLnB1c2godW5yZXNvbHZlZExpbmspO1xyXG5cdFx0XHRcdH1cclxuXHRcdFx0fVxyXG5cdFx0fVxyXG5cdFx0VXRpbHMud3JpdGVBbmRPcGVuRmlsZShcclxuXHRcdFx0dGhpcy5hcHAsXHJcblx0XHRcdG91dEZpbGVOYW1lLFxyXG5cdFx0XHRbXHJcblx0XHRcdFx0XCJEb24ndCBmb3JnZXQgdGhhdCBjcmVhdGluZyB0aGUgZmlsZSBmcm9tIGhlcmUgbWF5IGNyZWF0ZSB0aGUgZmlsZSBpbiB0aGUgd3JvbmcgZGlyZWN0b3J5IVwiLFxyXG5cdFx0XHRcdC4uLmxpbmtzLm1hcCgoZSkgPT4gYC0gW1ske2UubGlua31dXSBpbiBbWyR7ZS5maWxlcy5qb2luKFwiXV0sIFtbXCIpfV1dYClcclxuXHRcdFx0XS5qb2luKFwiXFxuXCIpKTtcclxuXHJcblx0fVxyXG5cclxuXHRmaW5kRmlsZXNXaXRob3V0VGFncygpIHtcclxuXHRcdGNvbnN0IG91dEZpbGVOYW1lID0gdGhpcy5zZXR0aW5ncy53aXRob3V0VGFnc091dHB1dEZpbGVOYW1lICsgXCIubWRcIjtcclxuXHRcdGxldCBvdXRGaWxlOiBURmlsZTtcclxuXHRcdGNvbnN0IGZpbGVzID0gdGhpcy5hcHAudmF1bHQuZ2V0TWFya2Rvd25GaWxlcygpO1xyXG5cdFx0bGV0IHdpdGhvdXRGaWxlcyA9IGZpbGVzLmZpbHRlcigoZmlsZSkgPT4ge1xyXG5cdFx0XHRpZiAobmV3IFV0aWxzKHRoaXMuYXBwLCBmaWxlLnBhdGgsIFtdLCBbXSwgdGhpcy5zZXR0aW5ncy53aXRob3V0VGFnc0RpcmVjdG9yaWVzVG9JZ25vcmUsIHRoaXMuc2V0dGluZ3Mud2l0aG91dFRhZ3NGaWxlc1RvSWdub3JlLCB0cnVlKS5pc1ZhbGlkKCkpIHtcclxuXHRcdFx0XHRyZXR1cm4gKGdldEFsbFRhZ3ModGhpcy5hcHAubWV0YWRhdGFDYWNoZS5nZXRGaWxlQ2FjaGUoZmlsZSkpLmxlbmd0aCA/PyAwKSA8PSAwO1xyXG5cclxuXHRcdFx0fSBlbHNlIHtcclxuXHRcdFx0XHRyZXR1cm4gZmFsc2U7XHJcblx0XHRcdH1cclxuXHRcdH0pO1xyXG5cdFx0d2l0aG91dEZpbGVzLnJlbW92ZShvdXRGaWxlKTtcclxuXHJcblxyXG5cdFx0bGV0IHByZWZpeDogc3RyaW5nO1xyXG5cdFx0aWYgKHRoaXMuc2V0dGluZ3MuZGlzYWJsZVdvcmtpbmdMaW5rcylcclxuXHRcdFx0cHJlZml4ID0gXCJcdFwiO1xyXG5cdFx0ZWxzZVxyXG5cdFx0XHRwcmVmaXggPSBcIlwiO1xyXG5cdFx0Y29uc3QgdGV4dCA9IHdpdGhvdXRGaWxlcy5tYXAoKGZpbGUpID0+IGAke3ByZWZpeH0tIFtbJHtmaWxlLnBhdGh9XV1gKS5qb2luKFwiXFxuXCIpO1xyXG5cdFx0VXRpbHMud3JpdGVBbmRPcGVuRmlsZSh0aGlzLmFwcCwgb3V0RmlsZU5hbWUsIHRleHQpO1xyXG5cdH1cclxuXHJcblx0LyoqXHJcblx0ICogQ2hlY2tzIGlmIHRoZSBnaXZlbiBmaWxlIGluIGFuIHVubGlua2VkIGZpbGVcclxuXHQgKiBcclxuXHQgKiBAcGFyYW0gZmlsZSBmaWxlIHRvIGNoZWNrXHJcblx0ICogQHBhcmFtIGxpbmtzIGFsbCBsaW5rcyBpbiB0aGUgdmF1bHRcclxuXHQgKi9cclxuXHRpc1ZhbGlkKGZpbGU6IFRGaWxlLCBsaW5rczogc3RyaW5nW10pOiBib29sZWFuIHtcclxuXHRcdGlmIChsaW5rcy5jb250YWlucyhmaWxlLnBhdGgpKVxyXG5cdFx0XHRyZXR1cm4gZmFsc2U7XHJcblxyXG5cdFx0Ly9maWxldHlwZXMgdG8gaWdub3JlIGJ5IGRlZmF1bHRcclxuXHRcdGlmIChmaWxlLmV4dGVuc2lvbiA9PSBcImNzc1wiKVxyXG5cdFx0XHRyZXR1cm4gZmFsc2U7XHJcblxyXG5cdFx0aWYgKHRoaXMuc2V0dGluZ3MuZmlsZVR5cGVzVG9JZ25vcmVbMF0gIT09IFwiXCIpIHtcclxuXHRcdFx0Y29uc3QgY29udGFpbnNGaWxlVHlwZSA9IHRoaXMuc2V0dGluZ3MuZmlsZVR5cGVzVG9JZ25vcmUuY29udGFpbnMoZmlsZS5leHRlbnNpb24pO1xyXG5cdFx0XHRpZiAodGhpcy5zZXR0aW5ncy5pZ25vcmVGaWxlVHlwZXMpIHtcclxuXHRcdFx0XHRpZiAoY29udGFpbnNGaWxlVHlwZSkgcmV0dXJuO1xyXG5cdFx0XHR9IGVsc2Uge1xyXG5cdFx0XHRcdGlmICghY29udGFpbnNGaWxlVHlwZSkgcmV0dXJuO1xyXG5cdFx0XHR9XHJcblx0XHR9XHJcblxyXG5cdFx0Y29uc3QgdXRpbHMgPSBuZXcgVXRpbHMoXHJcblx0XHRcdHRoaXMuYXBwLFxyXG5cdFx0XHRmaWxlLnBhdGgsXHJcblx0XHRcdHRoaXMuc2V0dGluZ3MudGFnc1RvSWdub3JlLFxyXG5cdFx0XHR0aGlzLnNldHRpbmdzLmxpbmtzVG9JZ25vcmUsXHJcblx0XHRcdHRoaXMuc2V0dGluZ3MuZGlyZWN0b3JpZXNUb0lnbm9yZSxcclxuXHRcdFx0dGhpcy5zZXR0aW5ncy5maWxlc1RvSWdub3JlLFxyXG5cdFx0XHR0aGlzLnNldHRpbmdzLmlnbm9yZURpcmVjdG9yaWVzXHJcblx0XHQpO1xyXG5cdFx0aWYgKCF1dGlscy5pc1ZhbGlkKCkpXHJcblx0XHRcdHJldHVybiBmYWxzZTtcclxuXHJcblx0XHRyZXR1cm4gdHJ1ZTtcclxuXHR9XHJcblxyXG5cclxuXHJcblx0b251bmxvYWQoKSB7XHJcblx0XHRjb25zb2xlLmxvZygndW5sb2FkaW5nICcgKyB0aGlzLm1hbmlmZXN0Lm5hbWUgKyBcIiBwbHVnaW5cIik7XHJcblx0fVxyXG5cdGFzeW5jIGxvYWRTZXR0aW5ncygpIHtcclxuXHRcdHRoaXMuc2V0dGluZ3MgPSBPYmplY3QuYXNzaWduKERFRkFVTFRfU0VUVElOR1MsIGF3YWl0IHRoaXMubG9hZERhdGEoKSk7XHJcblx0fVxyXG5cclxuXHRhc3luYyBzYXZlU2V0dGluZ3MoKSB7XHJcblx0XHRhd2FpdCB0aGlzLnNhdmVEYXRhKHRoaXMuc2V0dGluZ3MpO1xyXG5cdH1cclxufVxyXG4iXSwibmFtZXMiOlsiTW9kYWwiLCJub3JtYWxpemVQYXRoIiwiU2V0dGluZyIsIlBsdWdpblNldHRpbmdUYWIiLCJnZXRBbGxUYWdzIiwiaXRlcmF0ZUNhY2hlUmVmcyIsImdldExpbmtwYXRoIiwiTm90aWNlIiwiUGx1Z2luIl0sIm1hcHBpbmdzIjoiOzs7O0FBQUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQSxJQUFJLGFBQWEsR0FBRyxTQUFTLENBQUMsRUFBRSxDQUFDLEVBQUU7QUFDbkMsSUFBSSxhQUFhLEdBQUcsTUFBTSxDQUFDLGNBQWM7QUFDekMsU0FBUyxFQUFFLFNBQVMsRUFBRSxFQUFFLEVBQUUsWUFBWSxLQUFLLElBQUksVUFBVSxDQUFDLEVBQUUsQ0FBQyxFQUFFLEVBQUUsQ0FBQyxDQUFDLFNBQVMsR0FBRyxDQUFDLENBQUMsRUFBRSxDQUFDO0FBQ3BGLFFBQVEsVUFBVSxDQUFDLEVBQUUsQ0FBQyxFQUFFLEVBQUUsS0FBSyxJQUFJLENBQUMsSUFBSSxDQUFDLEVBQUUsSUFBSSxNQUFNLENBQUMsU0FBUyxDQUFDLGNBQWMsQ0FBQyxJQUFJLENBQUMsQ0FBQyxFQUFFLENBQUMsQ0FBQyxFQUFFLENBQUMsQ0FBQyxDQUFDLENBQUMsR0FBRyxDQUFDLENBQUMsQ0FBQyxDQUFDLENBQUMsRUFBRSxDQUFDO0FBQzFHLElBQUksT0FBTyxhQUFhLENBQUMsQ0FBQyxFQUFFLENBQUMsQ0FBQyxDQUFDO0FBQy9CLENBQUMsQ0FBQztBQUNGO0FBQ08sU0FBUyxTQUFTLENBQUMsQ0FBQyxFQUFFLENBQUMsRUFBRTtBQUNoQyxJQUFJLElBQUksT0FBTyxDQUFDLEtBQUssVUFBVSxJQUFJLENBQUMsS0FBSyxJQUFJO0FBQzdDLFFBQVEsTUFBTSxJQUFJLFNBQVMsQ0FBQyxzQkFBc0IsR0FBRyxNQUFNLENBQUMsQ0FBQyxDQUFDLEdBQUcsK0JBQStCLENBQUMsQ0FBQztBQUNsRyxJQUFJLGFBQWEsQ0FBQyxDQUFDLEVBQUUsQ0FBQyxDQUFDLENBQUM7QUFDeEIsSUFBSSxTQUFTLEVBQUUsR0FBRyxFQUFFLElBQUksQ0FBQyxXQUFXLEdBQUcsQ0FBQyxDQUFDLEVBQUU7QUFDM0MsSUFBSSxDQUFDLENBQUMsU0FBUyxHQUFHLENBQUMsS0FBSyxJQUFJLEdBQUcsTUFBTSxDQUFDLE1BQU0sQ0FBQyxDQUFDLENBQUMsSUFBSSxFQUFFLENBQUMsU0FBUyxHQUFHLENBQUMsQ0FBQyxTQUFTLEVBQUUsSUFBSSxFQUFFLEVBQUUsQ0FBQyxDQUFDO0FBQ3pGLENBQUM7QUF1Q0Q7QUFDTyxTQUFTLFNBQVMsQ0FBQyxPQUFPLEVBQUUsVUFBVSxFQUFFLENBQUMsRUFBRSxTQUFTLEVBQUU7QUFDN0QsSUFBSSxTQUFTLEtBQUssQ0FBQyxLQUFLLEVBQUUsRUFBRSxPQUFPLEtBQUssWUFBWSxDQUFDLEdBQUcsS0FBSyxHQUFHLElBQUksQ0FBQyxDQUFDLFVBQVUsT0FBTyxFQUFFLEVBQUUsT0FBTyxDQUFDLEtBQUssQ0FBQyxDQUFDLEVBQUUsQ0FBQyxDQUFDLEVBQUU7QUFDaEgsSUFBSSxPQUFPLEtBQUssQ0FBQyxLQUFLLENBQUMsR0FBRyxPQUFPLENBQUMsRUFBRSxVQUFVLE9BQU8sRUFBRSxNQUFNLEVBQUU7QUFDL0QsUUFBUSxTQUFTLFNBQVMsQ0FBQyxLQUFLLEVBQUUsRUFBRSxJQUFJLEVBQUUsSUFBSSxDQUFDLFNBQVMsQ0FBQyxJQUFJLENBQUMsS0FBSyxDQUFDLENBQUMsQ0FBQyxFQUFFLENBQUMsT0FBTyxDQUFDLEVBQUUsRUFBRSxNQUFNLENBQUMsQ0FBQyxDQUFDLENBQUMsRUFBRSxFQUFFO0FBQ25HLFFBQVEsU0FBUyxRQUFRLENBQUMsS0FBSyxFQUFFLEVBQUUsSUFBSSxFQUFFLElBQUksQ0FBQyxTQUFTLENBQUMsT0FBTyxDQUFDLENBQUMsS0FBSyxDQUFDLENBQUMsQ0FBQyxFQUFFLENBQUMsT0FBTyxDQUFDLEVBQUUsRUFBRSxNQUFNLENBQUMsQ0FBQyxDQUFDLENBQUMsRUFBRSxFQUFFO0FBQ3RHLFFBQVEsU0FBUyxJQUFJLENBQUMsTUFBTSxFQUFFLEVBQUUsTUFBTSxDQUFDLElBQUksR0FBRyxPQUFPLENBQUMsTUFBTSxDQUFDLEtBQUssQ0FBQyxHQUFHLEtBQUssQ0FBQyxNQUFNLENBQUMsS0FBSyxDQUFDLENBQUMsSUFBSSxDQUFDLFNBQVMsRUFBRSxRQUFRLENBQUMsQ0FBQyxFQUFFO0FBQ3RILFFBQVEsSUFBSSxDQUFDLENBQUMsU0FBUyxHQUFHLFNBQVMsQ0FBQyxLQUFLLENBQUMsT0FBTyxFQUFFLFVBQVUsSUFBSSxFQUFFLENBQUMsRUFBRSxJQUFJLEVBQUUsQ0FBQyxDQUFDO0FBQzlFLEtBQUssQ0FBQyxDQUFDO0FBQ1AsQ0FBQztBQUNEO0FBQ08sU0FBUyxXQUFXLENBQUMsT0FBTyxFQUFFLElBQUksRUFBRTtBQUMzQyxJQUFJLElBQUksQ0FBQyxHQUFHLEVBQUUsS0FBSyxFQUFFLENBQUMsRUFBRSxJQUFJLEVBQUUsV0FBVyxFQUFFLElBQUksQ0FBQyxDQUFDLENBQUMsQ0FBQyxHQUFHLENBQUMsRUFBRSxNQUFNLENBQUMsQ0FBQyxDQUFDLENBQUMsQ0FBQyxDQUFDLE9BQU8sQ0FBQyxDQUFDLENBQUMsQ0FBQyxDQUFDLEVBQUUsRUFBRSxJQUFJLEVBQUUsRUFBRSxFQUFFLEdBQUcsRUFBRSxFQUFFLEVBQUUsRUFBRSxDQUFDLEVBQUUsQ0FBQyxFQUFFLENBQUMsRUFBRSxDQUFDLENBQUM7QUFDckgsSUFBSSxPQUFPLENBQUMsR0FBRyxFQUFFLElBQUksRUFBRSxJQUFJLENBQUMsQ0FBQyxDQUFDLEVBQUUsT0FBTyxFQUFFLElBQUksQ0FBQyxDQUFDLENBQUMsRUFBRSxRQUFRLEVBQUUsSUFBSSxDQUFDLENBQUMsQ0FBQyxFQUFFLEVBQUUsT0FBTyxNQUFNLEtBQUssVUFBVSxLQUFLLENBQUMsQ0FBQyxNQUFNLENBQUMsUUFBUSxDQUFDLEdBQUcsV0FBVyxFQUFFLE9BQU8sSUFBSSxDQUFDLEVBQUUsQ0FBQyxFQUFFLENBQUMsQ0FBQztBQUM3SixJQUFJLFNBQVMsSUFBSSxDQUFDLENBQUMsRUFBRSxFQUFFLE9BQU8sVUFBVSxDQUFDLEVBQUUsRUFBRSxPQUFPLElBQUksQ0FBQyxDQUFDLENBQUMsRUFBRSxDQUFDLENBQUMsQ0FBQyxDQUFDLEVBQUUsQ0FBQyxFQUFFO0FBQ3RFLElBQUksU0FBUyxJQUFJLENBQUMsRUFBRSxFQUFFO0FBQ3RCLFFBQVEsSUFBSSxDQUFDLEVBQUUsTUFBTSxJQUFJLFNBQVMsQ0FBQyxpQ0FBaUMsQ0FBQyxDQUFDO0FBQ3RFLFFBQVEsT0FBTyxDQUFDLEVBQUUsSUFBSTtBQUN0QixZQUFZLElBQUksQ0FBQyxHQUFHLENBQUMsRUFBRSxDQUFDLEtBQUssQ0FBQyxHQUFHLEVBQUUsQ0FBQyxDQUFDLENBQUMsR0FBRyxDQUFDLEdBQUcsQ0FBQyxDQUFDLFFBQVEsQ0FBQyxHQUFHLEVBQUUsQ0FBQyxDQUFDLENBQUMsR0FBRyxDQUFDLENBQUMsT0FBTyxDQUFDLEtBQUssQ0FBQyxDQUFDLEdBQUcsQ0FBQyxDQUFDLFFBQVEsQ0FBQyxLQUFLLENBQUMsQ0FBQyxJQUFJLENBQUMsQ0FBQyxDQUFDLEVBQUUsQ0FBQyxDQUFDLEdBQUcsQ0FBQyxDQUFDLElBQUksQ0FBQyxJQUFJLENBQUMsQ0FBQyxDQUFDLEdBQUcsQ0FBQyxDQUFDLElBQUksQ0FBQyxDQUFDLEVBQUUsRUFBRSxDQUFDLENBQUMsQ0FBQyxDQUFDLEVBQUUsSUFBSSxFQUFFLE9BQU8sQ0FBQyxDQUFDO0FBQ3pLLFlBQVksSUFBSSxDQUFDLEdBQUcsQ0FBQyxFQUFFLENBQUMsRUFBRSxFQUFFLEdBQUcsQ0FBQyxFQUFFLENBQUMsQ0FBQyxDQUFDLEdBQUcsQ0FBQyxFQUFFLENBQUMsQ0FBQyxLQUFLLENBQUMsQ0FBQztBQUNwRCxZQUFZLFFBQVEsRUFBRSxDQUFDLENBQUMsQ0FBQztBQUN6QixnQkFBZ0IsS0FBSyxDQUFDLENBQUMsQ0FBQyxLQUFLLENBQUMsRUFBRSxDQUFDLEdBQUcsRUFBRSxDQUFDLENBQUMsTUFB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
