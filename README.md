# Objc2020
A versatile Objective-C macro language.

```objc

LET_VAR(var, ⁼, ...);

LET_TOGGLE(isSelected);

LET_KVC(object, key);
LET_KVC(object, value, key);

LET_POST(notificationName);
LET_POST(notificationName, object);
LET_POST(notificationName, object, userInfo);

THE_COLOR(0xFFFFFF);
THE_COLOR(0xFFFFFF, alpha);
THE_COLOR(r, g, b);
THE_COLOR(r, g, b, alpha);

THE_WELF;
^ block() {
  welf...
  CALL_WELF(...);
}

[self ...];
=>
CALL_SELF(...);

THE_WEAKED(var);
^ block() {
  var_weaked...
}

... = THE_VALUE_IN({
  value = ...
});

... = THE_NULL_SAFETY(var);
... = THE_NULL_SAFETY(var, defaultValue);

[[[[object method0] method1] method2] ...];
=>
CALL_METHOD_CHAINED(object, method0, method1, method2, ...);

if IS_TRUES(a, b, c,...) {} => if(a && b && c &&, ...) {}

if IS_SOMETRUE(a, b, c,...) {} => if(a || b || c ||, ...) {}

FOR_IN_ITEM(objs) { 
  item...
}

FOR_INT_I(to) { 
  something 
}
FOR_INT_I(from, to)  { 
  something
}
FOR_INT_I(from, to, var) { 
  something 
}

 TYPED_IN(obj, NSObject, {
   obj...
 })

 RET_IF(condition);
 RET_IF(obj, condition);

```
