pipeline {

 agent any


 stages {

  stage('Build') {
   steps {
    sh 'g++ src/calculator.cpp -o calculator'
   }
  }

  stage('Test') {
   steps {
    sh 'g++ tests/test_calculator.cpp -o test'
    sh './test'
   }
  }

  stage('Docker Build') {
   steps {
    sh 'docker build -t ayush81080/calculator:latest .'
   }
  }

  stage('Docker Login') {
   steps {
    withCredentials([string(credentialsId: 'docker-token', variable: 'DOCKER_TOKEN')]) {
     sh 'echo $DOCKER_TOKEN | docker login -u ayush81080 --password-stdin'
    }
   }
  }

  stage('Docker Push') {
   steps {
    sh 'docker push ayush81080/calculator:latest'
   }
  }

  stage('Deploy') {
   steps {
    sh 'ansible-playbook -i ansible/inventory ansible/deploy.yml'
   }
  }

 }

 post {
        success {
            // Sends an email only if checkout, build, tests, and push all succeed
            mail to: 'ayush81080@gmail.com',
                 subject: "SUCCESS: Jenkins Build #${env.BUILD_ID} for SPE-Mini-Project",
                 body: "Good news! Your Jenkins pipeline successfully built the project, passed all test cases, and pushed the new image to Docker Hub.\n\nCheck the build details here: ${env.BUILD_URL}"
        }
        failure {
            // It's best practice to also know if something broke!
            mail to: 'ayush81080@gmail.com',
                 subject: "FAILED: Jenkins Build #${env.BUILD_ID} for SPE-Mini-Project",
                 body: "The Jenkins pipeline failed. Please check the console logs to see what went wrong:\n\n${env.BUILD_URL}"
        }
    }

}
