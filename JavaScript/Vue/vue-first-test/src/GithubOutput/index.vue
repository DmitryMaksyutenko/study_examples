<template>
    <div>
        <p v-if="currentUsername == null">
            Enter a username above to see the data.
        </p>
        <p v-else>{{ currentUsername }} data:
            <github-user-data v-bind:data="githubData[currentUsername]"></github-user-data>
        </p>
    </div>
</template>
<script src="./script.js"></script>
<style scoped src="./style.css"></style>
