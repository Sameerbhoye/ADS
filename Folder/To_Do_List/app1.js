let app=angular.module("ToDoApp",[])
app.controller("ToDoController",function($scope){
$scope.todos=[];

$scope.addTodo=function(){
    if($scope.newTodo){
        $scope.todos.push({text:$scope.newTodo, isEditing:false});
        $scope.newTodo="";

    }
};
$scope.deleteTodo=function(index){
    $scope.todos.splice(index,1);
};
$scope.editTodo=function(todo){
    todo.isEditing=true;
};
$scope.saveTodo=function(todo){
    todo.isEditing=false
};
})