--- src/text-editor-component.js.orig	2020-05-18 19:34:10 UTC
+++ src/text-editor-component.js
@@ -1812,7 +1812,7 @@ module.exports = class TextEditorComponent {
     // the paste event. And since we don't use the `paste` event for any
     // behavior in Atom, we can no-op the event to eliminate this issue.
     // See https://github.com/atom/atom/pull/15183#issue-248432413.
-    if (this.getPlatform() === 'linux') event.preventDefault();
+    if (this.getPlatform() === 'linux' || this.getPlatform() === 'freebsd') event.preventDefault();
   }
 
   didTextInput(event) {
@@ -1976,7 +1976,7 @@ module.exports = class TextEditorComponent {
       // On Linux, pasting happens on middle click. A textInput event with the
       // contents of the selection clipboard will be dispatched by the browser
       // automatically on mouseup.
-      if (platform === 'linux' && this.isInputEnabled())
+      if ((platform === 'linux' || platform === 'freebsd') && this.isInputEnabled())
         model.insertText(clipboard.readText('selection'));
       return;
     }
@@ -2846,7 +2846,7 @@ module.exports = class TextEditorComponent {
   didChangeSelectionRange() {
     const { model } = this.props;
 
-    if (this.getPlatform() === 'linux') {
+    if (this.getPlatform() === 'linux' || this.getPlatform() === 'freebsd') {
       if (this.selectionClipboardImmediateId) {
         clearImmediate(this.selectionClipboardImmediateId);
       }
