function showScope() {
    scope = "local";
    return scope;
   }
scope = "global";
console.log(scope); // displays "global"
console.log(showScope()); // displays "local"
console.log(scope); // displays "local