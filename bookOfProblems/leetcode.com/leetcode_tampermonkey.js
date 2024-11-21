// ==UserScript==
// @name         LeetCode solution cleaner
// @namespace    http://tampermonkey.net/
// @version      2024-06-15
// @description  Clear leetcode problem solution
// @author       Marat
// @match        http://leetcode.com/problems/*
// @match        https://leetcode.com/problems/*
// @icon         data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==
// @grant        none
// ==/UserScript==

(function () {
    'use strict';

    const safeKeys = new Set(['global_lang-updated-time', 'gbFeaturesCache', 'QD_LAYOUT_JSON', 'used-dynamic-layout', 'global_lang', 'EDITOR_SETTING', 'random-uuid', 'announcementExpiration', 'report_random_id']);
    const keysToRemove = [];

    for (const key in localStorage) {
        if (localStorage.hasOwnProperty(key)) {
            if (!safeKeys.has(key) && !key.endsWith('_lang') && !key.startsWith('gr_imp_')) {
                keysToRemove.push(key);
            }
        }
    }

    for (const key of keysToRemove) {
        localStorage.removeItem(key);
    }
})();