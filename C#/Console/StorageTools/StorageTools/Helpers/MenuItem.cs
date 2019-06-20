﻿using System;

namespace StorageTools.Helpers
{
    public sealed class MenuItem
    {
        public string Text { get; set; }
        public Action Action { get; set; }

        public MenuItem(string text, Action action)
        {
            Text = text;
            Action = action;
        }
    }
}
